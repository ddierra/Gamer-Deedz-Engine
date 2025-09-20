#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Components/UserInput.hpp"
#include "Entities/EntityManager.hpp"
#include "Components/Velocity.hpp"

class InputManager{
    public:
        InputManager(float speed = 0.25f) : UserSpeed(speed) {}
        void addEntity(Entity e) { entities.push_back(e); }
        void update(EntityManager& em);

    private:
        float UserSpeed;
        std::vector<Entity> entities; // Entities to process input for
};