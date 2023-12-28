#include "npc.h"


NPC::NPC(const Coords<int>& coords_, std::string name_, NpcType type_){
    coords = coords_;
    name = name_;
    type = type_;
} 

bool NPC::is_close(const std::shared_ptr<NPC> &other) {
    std::lock_guard<std::mutex> lck(mtx);
    int distance = 0;
    if (this -> type == SlaverType){
        distance = 10;
    } else if (this -> type == KnightType){
        distance = 10;
    } else if (this -> type == SquirrelType){
        distance = 5;
    }
    if (std::pow(coords.x - other->coords.x, 2) + std::pow(coords.y - other->coords.y, 2) <= std::pow(distance, 2))
        return true;
    else
        return false;
}

bool NPC::is_alive()
{
    std::lock_guard<std::mutex> lck(mtx);
    return alive;
}

void NPC::must_die()
{
    std::lock_guard<std::mutex> lck(mtx);
    alive = false;
}

void NPC::subscribe(std::shared_ptr<Observer> observer){
    observers.push_back(observer);
}

void NPC::print(std::ostream &os) {
        os << type<< " ";
        os << coords.x<< " ";
        os << coords.y << std::endl;
    }

void NPC::fight_notify(NPC& defender, bool win){
    for (auto &o : observers)
        o->on_fight(*this, defender, win);
}

std::ostream &operator<<(std::ostream &os, NPC &npc) {
    if (npc.type == 0)
        os << "Slaver ";
    else if(npc.type == 1)
        os << "Knight ";
    else if (npc.type == 2)
        os << "Squirrel ";
    os<< npc.name <<" "<< npc.coords << std::endl;
    return os;
}

void NPC::move(int shift_x, int shift_y, int max_x, int max_y) {
    std::lock_guard<std::mutex> lck(mtx);
    int move_distance = 0;

    if (this -> type == SlaverType){
        move_distance = 10;
    } else if (this -> type == KnightType){
        move_distance = 30;
    } else if (this -> type == SquirrelType){
        move_distance = 5;
    }

    shift_x = move_distance * shift_x;
    shift_y = move_distance * shift_y;

    if ((coords.x + shift_x >= 0) && (coords.x + shift_x <= max_x))
        coords.x += shift_x;
    if ((coords.y + shift_y >= 0) && (coords.y + shift_y <= max_y))
        coords.y += shift_y;
}