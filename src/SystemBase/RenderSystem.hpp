#pragma once
#include <SFML/Graphics.hpp>
#include "Entities/EntityManager.hpp"
#include <unordered_map>
#include "Components/Position.hpp"

class RenderSystem{
public:
    void update(sf::RenderWindow& window, EntityManager& em);
    void addEntity(Entity e,std::shared_ptr<sf::Shape> shape);
    void removeEntity(Entity e);

private:
    std::unordered_map<Entity, std::shared_ptr<sf::Shape>> renderMap;
};