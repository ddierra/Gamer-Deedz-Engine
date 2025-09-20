#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <utility>
#include <iostream>
#include "Components/UserInput.hpp"

class InputManager{
    public:
        void handleInput(sf::RenderWindow& window, UserInput& input);
        void update(sf::RenderWindow& window);
        bool isKeyPressed(int key);
        bool isMousePressed(int button);
        std::pair<int, int> getMousePosition();
};