#include "InputManager.hpp"
#include <SFML/Graphics.hpp>
#include "Entities/EntityManager.hpp"
#include <iostream>
#include "Components/Velocity.hpp"
#include "Components/Position.hpp"
#include "SystemBase/MovementSystem.hpp"
#include "Components/Transform.hpp"
#include "Components/UserInput.hpp"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gamer Deedz Engine");
    window.setFramerateLimit(60);

    EntityManager em;

    // Create entities
    Entity rectangleEntity = em.createEntity();
    em.addComponent<Position>(rectangleEntity, 200.f, 200.f);
    em.addComponent<Velocity>(rectangleEntity, 0.f, 0.f);
    em.addComponent<UserInput>(rectangleEntity);
    em.addComponent<TransformComponent>(rectangleEntity);


    Entity circleEntity = em.createEntity();
    em.addComponent<Position>(circleEntity, 400.f, 300.f);
    em.addComponent<Velocity>(circleEntity, 0.f, 0.f);
    em.addComponent<UserInput>(circleEntity);
    em.addComponent<TransformComponent>(circleEntity);
    

   // Get references to Position components
    auto rectPos = em.getComponent<Position>(rectangleEntity);
    auto circPos = em.getComponent<Position>(circleEntity);

    // Create shapes
    sf::RectangleShape rectangle(sf::Vector2f(100.f, 50.f));
    rectangle.setFillColor(sf::Color::Yellow);

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Blue);

    // Input manager and movement system
    InputManager inputMgr;
    inputMgr.addEntity(rectangleEntity);
    inputMgr.addEntity(circleEntity);

    MovementSystem movementSys;
    movementSys.addEntity(rectangleEntity);
    movementSys.addEntity(circleEntity);

   float userSpeed = 0.25f; // Movement speed

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();

        inputMgr.update(em, userSpeed);
        movementSys.update(em, dt);

        // Sync shapes with ECS positions
        rectangle.setPosition(rectPos->x, rectPos->y);
        circle.setPosition(circPos->x, circPos->y);

        window.clear(sf::Color::Black);
        window.draw(rectangle);
        window.draw(circle);
        window.display();
    }

    return 0;
}
