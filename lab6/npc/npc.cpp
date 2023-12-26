#include "npc.h"


NPC::NPC(const Coords<int>& coords_, std::string name_, NpcType type_){
    coords = coords_;
    name = name_;
    type = type_;
} 

bool NPC::is_close(const std::shared_ptr<NPC> &other, int distance) {
    if (std::pow(coords.x - other->coords.x, 2) + std::pow(coords.y - other->coords.y, 2) <= std::pow(distance, 2))
        return true;
    else
        return false;
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