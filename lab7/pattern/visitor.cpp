#include "visitor.h"

bool FightVisitor::visit(Slaver& defender, NPC& attacker) {
    bool win = (attacker.type == KnightType);
    attacker.fight_notify(defender, win);
    return win;
}

bool FightVisitor::visit(Knight& defender, NPC& attacker) {
    bool win = false;
    attacker.fight_notify(defender, win);
    return win;
}

bool FightVisitor::visit(Squirrel& defender, NPC& attacker) {
    bool win = (attacker.type != KnightType);
    attacker.fight_notify(defender, win);
    return win;
}