#pragma once

#include "npc.h"

class Squirrel: public NPC {
public:

    Squirrel() = default;
    Squirrel(const Coords<int>& coords_, std::string name_);

    bool accept(NPCVisitor& visitor, NPC& attacker);

    ~Squirrel() = default;

};