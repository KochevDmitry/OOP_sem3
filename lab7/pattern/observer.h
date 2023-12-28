#pragma once

#include <iostream>
#include <fstream>
#include "../npc/npc.h"


class ScreenObserver : public Observer {
private:
    ScreenObserver(){};
    std::mutex print_mtx;

public:
    static std::shared_ptr<Observer> get();
    void on_fight(NPC& attacker, NPC& defender, bool win) override;

    ~ScreenObserver() = default;
};