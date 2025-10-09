#include "RenderSystem.hpp"

void RenderSystem::update(sf::RenderWindow& window){
    for(auto& [entity, shape] : renderMap){
        window.draw(*shape);
    }
}

void RenderSystem::addEntity(Entity e,std::shared_ptr<sf::Shape> shape){
    renderMap[e] = shape;
}

void RenderSystem::removeEntity(Entity e){
    renderMap.erase(e);
}