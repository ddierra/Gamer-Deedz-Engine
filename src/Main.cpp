#include "InputManager.hpp"
#include <SFML/Graphics.hpp>
#include "EntityManager/EntityManager.hpp"
#include <iostream>
#include "Components/Position.hpp"
#include "Components/Velocity.hpp"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gamer Deedz Engine");
    InputManager input;
    EntityManager em;

    // Create entities
    Entity rectangleEntity = em.createEntity();
    em.addComponent<Position>(rectangleEntity, 200.f, 200.f);
    em.addComponent<Velocity>(rectangleEntity, 0.f, 0.f);

    Entity circleEntity = em.createEntity();
    em.addComponent<Position>(circleEntity, 400.f, 300.f);
    em.addComponent<Velocity>(circleEntity, 0.f, 0.f);

    // Get references to Position components
    auto rectPos = em.getComponent<Position>(rectangleEntity);
    auto circPos = em.getComponent<Position>(circleEntity);

    // Create shapes
    sf::RectangleShape rectangle(sf::Vector2f(100.f, 50.f));
    rectangle.setFillColor(sf::Color::Yellow);

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Blue);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        input.update(window);

        // Move rectangle with WASD
        if (input.isKeyPressed(sf::Keyboard::A)) rectPos->x -= 0.25f;
        if (input.isKeyPressed(sf::Keyboard::D)) rectPos->x += 0.25f;
        if (input.isKeyPressed(sf::Keyboard::W)) rectPos->y -= 0.25f;
        if (input.isKeyPressed(sf::Keyboard::S)) rectPos->y += 0.25f;

        // Move circle with arrow keys
        if (input.isKeyPressed(sf::Keyboard::Left)) circPos->x -= 0.25f;
        if (input.isKeyPressed(sf::Keyboard::Right)) circPos->x += 0.25f;
        if (input.isKeyPressed(sf::Keyboard::Up)) circPos->y -= 0.25f;
        if (input.isKeyPressed(sf::Keyboard::Down)) circPos->y += 0.25f;

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
