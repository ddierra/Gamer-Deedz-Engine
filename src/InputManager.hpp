#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <utility>
#include <iostream>

class InputManager{
    public:
        void update(sf::RenderWindow& window);
        bool isKeyPressed(int key);
        bool isMousePressed(int button);
        std::pair<int, int> getMousePosition();
};