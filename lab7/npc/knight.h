#pragma once

#include "npc.h"

class Knight: public NPC {
public:

    Knight() = default;
    Knight(const Coords<int>& coords_, std::string name_);

    bool accept(NPCVisitor& visitor, NPC& attacker) override;

    ~Knight() = default;

};