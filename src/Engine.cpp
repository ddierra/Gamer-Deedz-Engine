#include "Engine.hpp"

#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

sf::Color getRandomColor() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 255);

    return sf::Color(dis(gen), dis(gen), dis(gen));
}



void Engine::run() {
 sf::RenderWindow window(sf::VideoMode(800, 600), "Gamer Deedz Engine");
    window.setFramerateLimit(60);

    InputManager input;
    EntityManager em;

    sf::Font font;
    if (!font.loadFromFile("resources/fonts/arial.ttf")) {
        std::cerr << "Failed to load font\n";
    }

    SideBar sidebar;
    sidebar.initialize(150.f, 600.f, 0.f, 0.f, sf::Color(50, 50, 50));

    // Create a rectangle entity
    sidebar.addButton(ButtonDefinitions::SpawnRectangle(font, "Add Rectangle", [&em](){
        Entity rectangleEntity = em.createEntity();
        em.addComponent<Position>(rectangleEntity, 200.f, 200.f);
        em.addComponent<Velocity>(rectangleEntity, 0.f, 0.f);
        em.addComponent<TransformComponent>(rectangleEntity);

        sf::RectangleShape rectangle(sf::Vector2f(100.f, 50.f));
        rectangle.setFillColor(getRandomColor());
        std::cout << "Spawned Rectangle Entity ID: " << rectangleEntity << "\n";
        std::cout << "Random color RGB: "
                    << (int)rectangle.getFillColor().r << ", "
                    << (int)rectangle.getFillColor().g << ", "
                    << (int)rectangle.getFillColor().b << "\n";
    }));

    Entity circleEntity = em.createEntity();
    em.addComponent<Position>(circleEntity, 400.f, 300.f);
    em.addComponent<Velocity>(circleEntity, 0.f, 0.f);
    em.addComponent<UserInput>(circleEntity);
    em.addComponent<TransformComponent>(circleEntity);
    

   // Get references to Position components
    auto circPos = em.getComponent<Position>(circleEntity);

    // Create shapes

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Blue);

    // Input manager and movement system
    InputManager inputMgr;
    inputMgr.addEntity(circleEntity);

    MovementSystem movementSys;
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

        inputMgr.update(em, window, UserInput{});
        movementSys.update(em, dt);

        // Move circle with arrow keys
        if (input.isKeyPressed(sf::Keyboard::Left)) circPos->x -= 0.25f;
        if (input.isKeyPressed(sf::Keyboard::Right)) circPos->x += 0.25f;
        if (input.isKeyPressed(sf::Keyboard::Up)) circPos->y -= 0.25f;
        if (input.isKeyPressed(sf::Keyboard::Down)) circPos->y += 0.25f;

        // Sync shapes with ECS positions
        circle.setPosition(circPos->x, circPos->y);

        window.clear(sf::Color::White);
        window.draw(circle);
        window.draw(sidebar.background);
        sidebar.render(window);
        sidebar.handleInput(window);
        window.display();
    }
}
