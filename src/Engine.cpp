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
    RenderSystem renderSys;

    sf::Font font;
    if (!font.loadFromFile("resources/fonts/arial.ttf")) {
        std::cerr << "Failed to load font\n";
    }

    SideBar sidebar;
    sidebar.initialize(150.f, 600.f, 0.f, 0.f, sf::Color(50, 50, 50));

    // Create a rectangle entity
    sidebar.addButton(ButtonDefinitions::SpawnRectangle(font, [&em, &renderSys](){
        Entity rectangleEntity = em.createEntity();
        em.addComponent<Position>(rectangleEntity, 200.f, 200.f);
        em.addComponent<Velocity>(rectangleEntity, 0.f, 0.f);
        em.addComponent<TransformComponent>(rectangleEntity);

        auto rectangle = std::make_shared<sf::RectangleShape>(sf::Vector2f(100.f, 50.f));
        rectangle->setFillColor(getRandomColor());
        rectangle->setPosition(200.f, 200.f);
        std::cout << "Spawned Rectangle Entity ID: " << rectangleEntity << "\n";
        std::cout << "Random color RGB: "
                    << (int)rectangle->getFillColor().r << ", "
                    << (int)rectangle->getFillColor().g << ", "
                    << (int)rectangle->getFillColor().b << "\n";

        renderSys.addEntity(rectangleEntity, rectangle);
    }));

    // Create a circle entity
    sidebar.addButton(ButtonDefinitions::SpawnCircle(font, [&em, &renderSys](){
        Entity circleEntity = em.createEntity();
        em.addComponent<Position>(circleEntity, 400.f, 300.f);
        em.addComponent<Velocity>(circleEntity, 0.f, 0.f);
        em.addComponent<TransformComponent>(circleEntity);

        auto circle = std::make_shared<sf::CircleShape>(40.f);
        circle->setFillColor(getRandomColor());
        circle->setPosition(400.f, 300.f);
        std::cout << "Spawned Circle Entity ID: " << circleEntity << "\n";
        std::cout << "Random color RGB: "
                    << (int)circle->getFillColor().r << ", "
                    << (int)circle->getFillColor().g << ", "
                    << (int)circle->getFillColor().b << "\n";

        renderSys.addEntity(circleEntity, circle);
    }));

    //Change Color of entities
    ColorSystem colorSys;
    sidebar.addButton(ButtonDefinitions::ChangeColor(font, [&em, &colorSys]() {
        colorSys.pickColor(em);
    }));

    Entity userEntity = em.createEntity();
    em.addComponent<Position>(userEntity, 300.f, 500.f);
    em.addComponent<Velocity>(userEntity, 0.f, 0.f);
    em.addComponent<TransformComponent>(userEntity);
    auto userEN = std::make_shared<sf::CircleShape>(20.f);
    userEN->setFillColor(sf::Color::Blue);
    userEN->setPosition(300.f, 500.f);


    // Input manager and movement system
    InputManager inputMgr;
    MovementSystem movementSys;

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

        sidebar.handleInput(window);
        window.clear(sf::Color::White);
        window.draw(*userEN);
        renderSys.update(window, em);
        sidebar.render(window);
        window.display();
    }
}
