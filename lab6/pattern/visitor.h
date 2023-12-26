#pragma once

#include <iostream>
#include "../npc/npc.h"
#include "../npc/knight.h"
#include "../npc/slaver.h"
#include "../npc/squirrel.h"
#include "observer.h"


class FightVisitor : public NPCVisitor {
public:
    bool visit(Slaver& defender, NPC& attacker) override;
    bool visit(Knight& defender, NPC& attacker) override;
    bool visit(Squirrel& defender, NPC& attacker) override;
};
