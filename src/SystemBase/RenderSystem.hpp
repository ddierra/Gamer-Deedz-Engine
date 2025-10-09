#pragma once
#include <SFML/Graphics.hpp>
#include "Entities/EntityManager.hpp"
#include <unordered_map>

class RenderSystem{
public:
    void update(sf::RenderWindow& window);
    void addEntity(Entity e,std::shared_ptr<sf::Shape> shape);
    void removeEntity(Entity e);

private:
    std::unordered_map<Entity, std::shared_ptr<sf::Shape>> renderMap;
};