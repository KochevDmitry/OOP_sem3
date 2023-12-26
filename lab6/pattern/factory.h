#pragma once

#include <iostream>
#include <memory>
#include "../npc/npc.h"
#include "../npc/slaver.h"
#include "../npc/knight.h"
#include "../npc/squirrel.h"
#include "observer.h"

class NPCFactory {
public:
    static std::shared_ptr<NPC> factory(NpcType type, const Coords<int>& coords);
};