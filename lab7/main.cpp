#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include "./npc/npc.h"
#include "./npc/slaver.h"
#include "./npc/knight.h"
#include "./npc/squirrel.h"
#include "./pattern/factory.h"
#include "./pattern/visitor.h"
#include "./pattern/observer.h"
#include "./coords/coords.h"
#include <set>

#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>
#include <shared_mutex>


using namespace std::chrono;
using set_t = std::set<std::shared_ptr<NPC>>;

std::mutex print_mutex;

std::ostream &operator<<(std::ostream &os, const set_t &array)
{
    for (auto &n : array)
        os<< *n;
    return os;
}

std::atomic<bool> isRunning{true};
struct FightTeam
{
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

void save(const set_t &array, const std::string &filename)
{
    std::string filepath = "../" + filename;
    std::ofstream fs(filepath);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->print(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string &filename)
{
    std::string filepath = "../" + filename;
    set_t result;
    std::ifstream is(filepath);
    if (!is.is_open()){
        std::cerr << "Error: " << std::endl;
    }
    int count, x, y;
    int type;
    is >> count;
    for (int i = 0; i < count; ++i){
        is >> type >> x >> y;
        result.insert(NPCFactory::factory(static_cast<NpcType>(type), Coords(x, y)));
    }
        
    is.close();
    
    return result;
}


class FightDistribute
{
private:
    std::queue<FightTeam> events;
    std::shared_mutex mtx;

    FightDistribute() {}

public:
    static FightDistribute &get()
    {
        static FightDistribute instance;
        return instance;
    }

    void add_event(FightTeam &&event)
    {
        std::lock_guard<std::shared_mutex> lock(mtx);
        events.push(event);
    }

    void operator()()
    {
        FightVisitor visitor;
        while (isRunning)
        {
            {
                std::optional<FightTeam> event;

                {
                    std::lock_guard<std::shared_mutex> lock(mtx);
                    if (!events.empty())
                    {
                        event = events.back();
                        events.pop();
                    }
                }

                if (event)
                {
                        if (event->attacker->is_alive())  
                            if (event->defender->is_alive()) 
                                if (event->defender->accept(visitor, *(event->attacker)))
                                    event->defender->must_die();
                }
                else
                    std::this_thread::sleep_for(500ms);
            }
        }
    }
    ~FightDistribute() = default;
};

int main()
{
    set_t array; // монстры

    const int MAX_X{100};
    const int MAX_Y{100};

    // Гененрируем начальное распределение монстров
    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 50; ++i)
        array.insert(NPCFactory::factory(NpcType(std::rand() % 3), Coords(std::rand() % MAX_X, std::rand() % MAX_Y)));

    std::cout << "Starting list:" << std::endl
              << array;

    std::thread fight_thread(std::ref(FightDistribute::get()));

    std::thread move_thread([&array, MAX_X, MAX_Y]() {
        while (isRunning){
            
            for (std::shared_ptr<NPC> npc : array)
            {
                if (npc->is_alive())
                {
                    int shift_x = (std::rand() % 2 == 0 ? -1 : 1);
                    int shift_y = (std::rand() % 2 == 0 ? -1 : 1);
                    npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                }
            }
        
            for (std::shared_ptr<NPC> npc : array)
            {
                for (std::shared_ptr<NPC> other : array)
                {
                    if (other != npc && npc->is_alive() && other->is_alive() && npc->is_close(other)){
                        FightDistribute::get().add_event({npc, other});
                    }
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    std::thread game_thread([]() {
        std::this_thread::sleep_for(std::chrono::seconds(30));
        isRunning = false;
    });
   
    while (isRunning)
    {
        int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
        {
            std::vector<char> fields(grid * grid, 0);
            for (std::shared_ptr<NPC> npc : array)
            {
                Coords<int> pos = npc->coords;
                int i = pos.x / step_x;
                int j = pos.y / step_y;

                if (npc->is_alive())
                {
                    switch (npc->type)
                    {
                    case SlaverType:
                        fields[i + grid * j] = 'S';
                        break;
                    case KnightType:
                        fields[i + grid * j] = 'K';
                        break;
                    case SquirrelType:
                        fields[i + grid * j] = 's';
                        break;

                    default:
                        break;
                    }
                }
                else
                {
                    fields[i + grid * j] = '.';
                }
            }

            std::lock_guard<std::mutex> lck(print_mutex);
            for (int j = 0; j < grid; ++j)
            {
                for (int i = 0; i < grid; ++i)
                {
                    char c = fields[i + j * grid];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(1s);
    };

    game_thread.join();
    move_thread.join();
    fight_thread.join();

    std::cout << std::endl;
    std::cout << "Ending list:" << std::endl;
    for(auto &npc: array){
        if(npc->is_alive()){
            std::cout << *npc;
        }
    }

    return 0;
}