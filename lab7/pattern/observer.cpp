#include "observer.h"



std::shared_ptr<Observer> ScreenObserver::get(){
    static ScreenObserver instance;
    return std::shared_ptr<Observer>(&instance, [](Observer *) {});
}

void ScreenObserver::on_fight(NPC& attacker, NPC& defender, bool win) {
    if (win){
        std::cout << std::endl
                << "Murder --------" << std::endl;
        std::cout << "Killer: ";
        std::cout << attacker;
        std::cout << "Victim: ";
        std::cout << defender;
    }
}