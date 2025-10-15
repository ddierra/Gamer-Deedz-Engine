#pragma  once
#include "Components/Color.hpp"
#include "Entities/EntityManager.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class ColorSystem{
    public:
        void pickColor(EntityManager& em);
};