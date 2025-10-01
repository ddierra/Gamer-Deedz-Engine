#include "Button.hpp"

 void button::render(sf::RenderWindow& window) {
    for (const auto& button : buttons) {
        window.draw(button.shape);
        window.draw(button.text);
    }
}

void button::addButton(const Button& button) {
    buttons.push_back(button);
}

void button::handleInput(sf::RenderWindow& window) {
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

void handleInput(sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        std::cout << "Left mouse presssed at position: " 
                  << pos.x << ", " << pos.y << std::endl;
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        std::cout << "Right mouse pressed at position: " 
                  << pos.x << ", " << pos.y << std::endl;
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        std::cout << "Middle mouse pressed at position: " 
                  << pos.x << ", " << pos.y << std::endl;
    }
}