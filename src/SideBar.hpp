#pragma once
#include <SFML/Graphics.hpp>
#include "InputManager.hpp"
#include <SFML/Window.hpp>
#include <vector>
#include "Button.hpp"

class SideBar {
    public:
        std::vector<Button> buttons;
        void initialize(float width, float height, float posX, float posY, const sf::Color& bgColor);
        sf::RectangleShape background;
        void render(sf::RenderWindow& window);
        void addButton(const Button& button);
        void handleInput(sf::RenderWindow& window);
};