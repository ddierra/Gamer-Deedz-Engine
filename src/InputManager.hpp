#pragma once
#include <SFML/Window.hpp>

class InputManager {
public:
    void update();
    bool isKeyPressed(sf::Keyboard::Key key);
    bool isMousePressed(sf::Mouse::Button button);
    sf::Vector2i getMousePosition();
};