#include "EntityManager.hpp"

void EntityManager::destroyEntity(Entity e) {
    for (auto& [type, compMap] : components) {
        compMap.erase(e);
    }
}
