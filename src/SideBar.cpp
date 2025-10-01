#include "SideBar.hpp"


void SideBar::render(sf::RenderWindow& window) {
    for (const auto& button : buttons) {
        window.draw(button.shape);
        window.draw(button.text);
    }
}

void SideBar::addButton(const Button& button) {
    buttons.push_back(button);
}

void SideBar::handleInput(sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        for (auto& button : buttons) {
            if (button.shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                if (button.onClick) {
                    button.onClick();
                }
            }
        }
    }
}