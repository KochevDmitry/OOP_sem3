#include "slaver.h"

Slaver::Slaver(const Coords<int>& coords_, std::string name_) : NPC(coords_, name_, SlaverType) {}

    
bool Slaver::accept(NPCVisitor& visitor, NPC& attacker) {
    return visitor.visit(*this, attacker);
}