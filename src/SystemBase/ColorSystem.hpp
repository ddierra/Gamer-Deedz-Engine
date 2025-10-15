#pragma  once
#include "Components/Color.hpp"
#include "Entities/EntityManager.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>

class ColorSystem{
    public:
        void pickColor(EntityManager& em);
};