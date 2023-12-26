#include <iostream>
#include <gtest/gtest.h>
#include "./npc/npc.h"
#include "./npc/slaver.h"
#include "./npc/knight.h"
#include "./npc/squirrel.h"
#include "./pattern/factory.h"
#include "./pattern/visitor.h"
#include "./pattern/observer.h"

TEST(test_01, basic_test_set) {
    std::shared_ptr<NPC> slaver = NPCFactory::factory(NpcType(0), Coords(std::rand() % 100, std::rand() % 100));
    std::shared_ptr<NPC> knight = NPCFactory::factory(NpcType(1), Coords(std::rand() % 100, std::rand() % 100));
    std::shared_ptr<NPC> squirrel = NPCFactory::factory(NpcType(2), Coords(std::rand() % 100, std::rand() % 100));

    ASSERT_TRUE(dynamic_cast<Slaver*>(slaver.get()) != nullptr);
    ASSERT_TRUE(dynamic_cast<Knight*>(knight.get()) != nullptr);
    ASSERT_TRUE(dynamic_cast<Squirrel*>(squirrel.get()) != nullptr);
}

TEST(test_02, basic_test_set) {
    FightVisitor visitor;

    std::shared_ptr<NPC> slaver = std::make_shared<Slaver>(Coords(1, 1), "DefaultSlaver");
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(Coords(2, 2), "DefaultKnight");
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(Coords(3, 3), "DefaultSquirrel1");
    std::shared_ptr<NPC> squirrel2 = std::make_shared<Squirrel>(Coords(5, 5), "DefaultSquirrel2");

    ASSERT_TRUE(squirrel->accept(visitor, *squirrel2));
    ASSERT_TRUE(squirrel2->accept(visitor, *slaver));
    ASSERT_TRUE(slaver->accept(visitor, *knight));
}

TEST(test_03, basic_test_set) {
    FightVisitor visitor;

    std::shared_ptr<NPC> slaver = std::make_shared<Slaver>(Coords(1, 1), "DefaultSlaver");
    std::shared_ptr<NPC> knight = std::make_shared<Knight>(Coords(2, 2), "DefaultKnight");
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(Coords(3, 3), "DefaultSquirrel1");
    std::shared_ptr<NPC> squirrel2 = std::make_shared<Squirrel>(Coords(5, 5), "DefaultSquirrel2");

    ASSERT_TRUE(squirrel->accept(visitor, *squirrel2));
    ASSERT_FALSE(slaver->accept(visitor, *squirrel2));
    ASSERT_FALSE(knight->accept(visitor, *slaver));
}

TEST(test_04, basic_test_set) {
     ASSERT_THROW((NPCFactory::factory(NpcType(10), Coords(1, 1))), std::invalid_argument);
}

TEST(test_05, basic_test_set) {
    std::shared_ptr<NPC> attacker = std::make_shared<Knight>(Coords(1, 1), "DefaultKnight");
    std::shared_ptr<NPC> defender = std::make_shared<Slaver>(Coords(3, 3), "DefaultSlaver");
    std::string filename = "../log.txt";
    std::shared_ptr<Observer> observer = FileObserver::get(filename);
    
    observer->on_fight(*attacker, *defender, true);

    std::ifstream file(filename);
    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    file.close();
    ASSERT_TRUE(content.find("Murder --------") != std::string::npos);
    ASSERT_TRUE(content.find("Killer: 1 1 1") != std::string::npos);
    ASSERT_TRUE(content.find("Victim: 0 3 3") != std::string::npos);
}

TEST(test_06, basic_test_set) {
    std::shared_ptr<NPC> attacker = std::make_shared<Knight>(Coords(1, 1), "DefaultKnight");
    std::shared_ptr<NPC> defender = std::make_shared<Slaver>(Coords(3, 3), "DefaultSlaver");
    std::shared_ptr<Observer> observer = ScreenObserver::get();
    
    testing::internal::CaptureStdout();
    observer->on_fight(*attacker, *defender, true);
    std::string output = testing::internal::GetCapturedStdout();
    
    ASSERT_EQ(output, "\nMurder --------\nKiller: Knight DefaultKnight (x: 1; y: 1)\nVictim: Slaver DefaultSlaver (x: 3; y: 3)\n");
}

TEST(test_07, basic_test_set) {
    std::shared_ptr<NPC> attacker = std::make_shared<Squirrel>(Coords(1, 1), "DefaultSquirrel1");
    std::shared_ptr<NPC> defender = std::make_shared<Squirrel>(Coords(3, 3), "DefaultSquirrel2");
    std::shared_ptr<Observer> observer = ScreenObserver::get();
    
    testing::internal::CaptureStdout();
    observer->on_fight(*attacker, *defender, true);
    std::string output = testing::internal::GetCapturedStdout();
    
    ASSERT_EQ(output, "\nMurder --------\nKiller: Squirrel DefaultSquirrel1 (x: 1; y: 1)\nVictim: Squirrel DefaultSquirrel2 (x: 3; y: 3)\n");
}

int main (int args, char **argv) {
    testing::InitGoogleTest(&args, argv);
    return RUN_ALL_TESTS();
}
