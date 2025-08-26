#include "InputManager.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void InputManager::update(sf::RenderWindow& window) {
    // Update input states if necessary

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        std::cout << "Escape key is pressed." << std::endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        rectangle.move(-0.1f, 0.f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        rectangle.move(0.1f, 0.f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        rectangle.move(0.f, -0.1f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        rectangle.move(0.f, 0.1f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        std::cout << "Space key is pressed." << std::endl;
    } 

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        std::cout << "Enter key is pressed." << std::endl;
    }   

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        circle.move(-0.1f, 0.f);
    } 

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        circle.move(0.1f, 0.f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        circle.move(0.f, -0.1f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        circle.move(0.f, 0.1f);
    }

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

bool InputManager::isKeyPressed(int key) {
    return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key));
}

bool InputManager::isMousePressed(int button) {
    return sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(button));
}

std::pair<int, int> InputManager::getMousePosition() {
    sf::Vector2i pos = sf::Mouse::getPosition();
    return std::make_pair(pos.x, pos.y);
}