#include "factory.h"

std::shared_ptr<NPC> NPCFactory::factory(NpcType type, const Coords<int>& coords) {
    std::shared_ptr<NPC> result;
    // std::cout<<coords<<" ";
    switch(type) {
        case NpcType::SlaverType:
            result = std::make_shared<Slaver>(coords, "DefaultSlaver");
            break;
        case NpcType::KnightType:
            result = std::make_shared<Knight>(coords, "DefaultKnight");
            break;
        case NpcType::SquirrelType:
            result = std::make_shared<Squirrel>(coords, "DefaultSquirrel");
            break;
        default:
            throw std::invalid_argument("Invalid type");
            break;
    }
    // std::cout<<*result<<" ";
    if(result){
        result->subscribe(ScreenObserver::get());
    }
    return result;
}