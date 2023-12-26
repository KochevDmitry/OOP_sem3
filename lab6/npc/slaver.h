#pragma once

#include "npc.h"

class Slaver: public NPC {
public:

    Slaver() = default;
    Slaver(const Coords<int>& coords_, std::string name_);

    bool accept(NPCVisitor& visitor, NPC& attacker);

    ~Slaver() = default;

};