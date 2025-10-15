#include "ColorSystem.hpp"

void ColorSystem::pickColor(EntityManager& em){
    int r, g, b;
    std::cout << "Enter RGB values (0-255); ";
    std::cin >> r >> g >> b;
    sf::Color newColor(r, g, b);

    for (auto e : em.getEntitiesWith<Color>()){
        auto colorComp = em.getComponent<Color>(e);
        colorComp->fillColor = newColor;
    }
};