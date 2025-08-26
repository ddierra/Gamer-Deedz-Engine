#include "InputManager.hpp"
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gamer Deedz Engine");

    InputManager input;

    //Add a simple shapes to visualize
    sf::RectangleShape rectangle(sf::Vector2f(100.f, 50.f));
    rectangle.setFillColor(sf::Color::Yellow);
    rectangle.setPosition(200.f, 200.f);

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(400.f, 300.f);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        input.update(window);

        window.clear(sf::Color::Black);
        window.draw(rectangle);
        window.draw(circle);
        window.display();
    }

    return 0;
}
