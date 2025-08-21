#include "InputManager.hpp"
#include <SFML/Window.hpp>

void InputManager::update() {
    // Update input states if necessary

    switch (sf::Keyboard::Unknown)
    {
    case sf::Keyboard::Escape:
        std::cout << "Escape key is pressed." << std::endl;
        break;
    case sf::Keyboard::A:
        std::cout << "A key is pressed." << std::endl;
        break;

    case sf::Keyboard::D:
        std::cout << "D key is pressed." << std::endl;
        break;
    
    case sf::Keyboard::W:
        std::cout << "W key is pressed." << std::endl;
        break;
    
    case sf::Keyboard::S:
        std::cout << "S key is pressed." << std::endl;
        break;

    case sf::Keyboard::Space:
        std::cout << "Space key is pressed." << std::endl;
        break;
    
    case sf::Keyboard::Enter:
        std::cout << "Enter key is pressed." << std::endl;
        break;

    case sf::Keyboard::Left:
        std::cout << "Left Arrow key is pressed." << std::endl;
        break;

    case sf::Keyboard::Right:
        std::cout << "Right Arrow key is pressed." << std::endl;
        break;

    case sf::Keyboard::Up:
        std::cout << "Up Arrow key is pressed." << std::endl;
        break;

    case sf::Keyboard::Down:
        std::cout << "Down Arrow key is pressed." << std::endl;
        break;
        
    default:
        break;
}

switch (sf::Mouse::Unknown, sf::Mouse::getPosition())
{
    case sf::Mouse::Left:
        std::cout << "Left mouse button pressed at position: (" 
                  << sf::Mouse::getPosition().x << ", " 
                  << sf::Mouse::getPosition().y << ")" << std::endl;
        break;
    
    case sf::Mouse::Right:
        std::cout << "Right mouse button pressed at position: (" 
                  << sf::Mouse::getPosition().x << ", " 
                  << sf::Mouse::getPosition().y << ")" << std::endl;
        break;

    case sf::Mouse::Middle:
        std::cout << "Middle mouse button pressed at position: (" 
                  << sf::Mouse::getPosition().x << ", " 
                  << sf::Mouse::getPosition().y << ")" << std::endl;
        break;

    default:
        break;
}
}