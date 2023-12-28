#include "squirrel.h"

    Squirrel::Squirrel(const Coords<int>& coords_, std::string name_) : NPC(coords_, name_, SquirrelType) {}

    bool Squirrel::accept(NPCVisitor& visitor, NPC& attacker) {
        return visitor.visit(*this, attacker);
    }