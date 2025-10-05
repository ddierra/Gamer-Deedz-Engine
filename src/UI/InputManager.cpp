#include "InputManager.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void InputManager::handleInput(sf::RenderWindow& window, UserInput& input) {
    // Handle events
    input = {}; // Reset input state
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }

    // Update input states based on key presses
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        input.up = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        input.down = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        input.left = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        input.right = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        input.jump = true;
    }
}

void InputManager::update(EntityManager& em, sf::RenderWindow& window, const UserInput& input) {
    // Update input states if necessary

    for(Entity e: entities) {
        // Process input for each entity if needed
        auto vel = em.getComponent<Velocity>(e);
        auto input = em.getComponent<UserInput>(e);

        if (! vel || !input) continue;{
            vel->vx += 0.f;
            vel->vy += 0.f;

            input->up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
            input->down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
            input->left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
            input->right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
            input->jump = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

            if(input->up) {
                vel->vy -= UserSpeed; // Move up
            }
            if(input->down) {
                vel->vy += UserSpeed; // Move down
            }
            if(input->left) {
                vel->vx -= UserSpeed; // Move left
            }
            if(input->right) {
                vel->vx += UserSpeed; // Move right
                }
            if(input->jump) {
                int i = 0;
                while(i < 1){ {
                    vel->vy -= UserSpeed * 2; // Jump (stronger upward force)
                    vel->vx += 0.f;
                    vel->vy += 0.f;
                    i++;
                }
            }
        }
    }
}

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        std::cout << "Escape key is pressed." << std::endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        std::cout << "A key is pressed." << std::endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        std::cout << "D key is pressed." << std::endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        std::cout << "W key is pressed." << std::endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        std::cout << "S key is pressed." << std::endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        std::cout << "Space key is pressed." << std::endl;
    } 

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        std::cout << "Enter key is pressed." << std::endl;
    }   

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        std::cout << "Left Arrow key is pressed." << std::endl;
    } 

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        std::cout << "Right Arrow key is pressed." << std::endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        std::cout << "Up Arrow key is pressed." << std::endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        std::cout << "Down Arrow key is pressed." << std::endl;
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

