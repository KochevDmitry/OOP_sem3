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
#include <set>

using set_t = std::set<std::shared_ptr<NPC>>;
std::ostream &operator<<(std::ostream &os, const set_t &array)
{
    for (auto &n : array)
        os << *n;
    return os;
}

void save(const set_t &array, const std::string &filename)
{
    std::string filepath = "../" + filename; // "../" если исполняемый файл в build (без этого, чтобы просто оставить в build)
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
        std::cerr << "Error:" << std::endl;
    }
    int count, x, y;
    int type;
    is >> count;
    for (int i = 0; i < count; ++i){
        is >> type >> x >> y;
        std::cout<<type<<" "<<x<<" "<<y<<std::endl; 
        result.insert(NPCFactory::factory(static_cast<NpcType>(type), Coords(x, y)));
    }
    is.close();
    
    return result;
}


set_t fight(const set_t& array, size_t distance) {
    set_t dead_list;

    FightVisitor visitor;

    for (const auto& attacker : array) {
        for (const auto& defender : array) {
            if ((attacker != defender) && (attacker->is_close(defender, distance))) {
                bool success{false};
                success = defender->accept(visitor, *attacker);
                if (success) {
                    dead_list.insert(defender);
                }
            }
        }
    }

    return dead_list;
}


int main(){
    set_t npcs;

    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 30; ++i)
        npcs.insert(NPCFactory::factory(NpcType(std::rand() % 3), Coords(std::rand() % 200, std::rand() % 200)));

    std::cout << "Saving ..." << std::endl;
    save(npcs, "npc.txt");

    std::cout << "Loading ..." << std::endl;
    npcs = load("npc.txt");

    std::cout << "Fighting ..."  << std::endl 
            << "_________NPCS_________"
                        << std::endl
                        << npcs
            << "______________________" 
            << std::endl << std::endl;

    for (size_t distance = 20; (distance <= 200) && !npcs.empty(); distance += 20)
    {
        std::cout << "_________NEW ROUND_________"  << std::endl;
        auto dead_list = fight(npcs, distance);
        for (auto &d : dead_list)
            npcs.erase(d);
        std::cout << "Fight stats ----------" << std::endl
                  << "distance: " << distance << std::endl
                  << "killed: " << dead_list.size() << std::endl
                  << std::endl;

    }

    std::cout << "Survivors: " << npcs;

    return 0;


}