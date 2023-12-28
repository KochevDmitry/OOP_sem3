#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <cmath>
#include <vector>
#include "../coords/coords.h"
#include <shared_mutex>

class NPC;
class Slaver;
class Squirrel;
class Knight;

enum NpcType
{
    SlaverType = 0,
    KnightType = 1,
    SquirrelType = 2,
};

class NPCVisitor {
    public:
        virtual bool visit(Slaver & slaver, NPC & attacker) = 0;
        virtual bool visit(Squirrel & squirrel, NPC & attacker) = 0;
        virtual bool visit(Knight & knight, NPC & attacker) = 0;
};

class Observer {
public:
    virtual void on_fight(NPC& attacker, NPC& defender, bool win) = 0;
};

class NPC {
    friend std::ostream &operator<<(std::ostream &os, NPC &npc);

    public:

        std::mutex mtx;
        bool alive{true};

        Coords<int> coords;
        NpcType type;
        std::string name;
        std::vector<std::shared_ptr<Observer>> observers;

        NPC() = default;
        NPC(const Coords<int> &coords, std::string name, NpcType type_);

        virtual bool accept(NPCVisitor& visitor, NPC& attacker) = 0;
        virtual bool is_close(const std::shared_ptr<NPC> &other);
        virtual void print(std::ostream &os);

        ~NPC() = default;


        void subscribe(std::shared_ptr<Observer> observer );
        void fight_notify(NPC& defender, bool win);

        void move(int shift_x, int shift_y, int max_x, int max_y);

        bool is_alive();
        void must_die();

};
