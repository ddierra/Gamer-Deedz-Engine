#include "RenderSystem.hpp"

void RenderSystem::update(sf::RenderWindow& window, EntityManager& em) {
for (auto& [entity, shape] : renderMap) {
    if (auto pos = em.getComponent<Position>(entity)) {
        shape->setPosition(pos->x, pos->y);
    }
    window.draw(*shape);
}

}

void RenderSystem::addEntity(Entity e,std::shared_ptr<sf::Shape> shape){
    renderMap[e] = shape;
}

void RenderSystem::removeEntity(Entity e){
    renderMap.erase(e);
}