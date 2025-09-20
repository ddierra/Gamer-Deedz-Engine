#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <utility>
#include <iostream>
#include "Components/UserInput.hpp"
#include "Entities/EntityManager.hpp"
#include "Components/Velocity.hpp"

class InputManager{
    public:
        void handleInput(sf::RenderWindow& window, UserInput& input);
        void addEntity(Entity e) { entities.push_back(e); }
        InputManager(float speed = 0.25f) : UserSpeed(speed) {}
        void update(EntityManager& em, sf::RenderWindow& window, const UserInput& input);
        bool isKeyPressed(int key);
        bool isMousePressed(int button);
        std::pair<int, int> getMousePosition();

    private:
        float UserSpeed;
        std::vector<Entity> entities; // Entities to process input for
};