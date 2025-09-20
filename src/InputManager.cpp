#include "InputManager.hpp"
#include <SFML/Window/Keyboard.hpp>

void InputManager::update(EntityManager& em){
    for (Entity e: entities) {
        auto vel = em.getComponent<Velocity>(e);
        auto input = em.getComponent<UserInput>(e);
        
        if (!vel || !input) continue; {

            *input = {}; // Reset input state
        }
        
        input->up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        input->down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        input->left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        input->right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        input->jump = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
        
    vel->vx = 0.f;
    vel->vy = 0.f;

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
        vel->vy -= UserSpeed * 1.5f; // Jump (stronger upward force)
        }
    }
}