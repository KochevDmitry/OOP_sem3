#include "knight.h"

Knight::Knight(const Coords<int>& coords_, std::string name_) : NPC(coords_, name_, KnightType) {}

bool Knight::accept(NPCVisitor& visitor, NPC& attacker) {
    return visitor.visit(*this, attacker);
}