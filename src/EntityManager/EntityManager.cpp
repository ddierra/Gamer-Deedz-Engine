#include "EntityManager.hpp"

Entity EntityManager::createEntity() {
    return nextEntity++;
}

void EntityManager::destroyEntity(Entity e) {
    for (auto& [type, compMap] : components) {
        compMap.erase(e);
    }
}
