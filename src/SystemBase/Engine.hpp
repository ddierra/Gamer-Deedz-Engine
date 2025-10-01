#include <SFML/Graphics.hpp>
#include "InputManager.hpp"
#include "Entities/EntityManager.hpp"
#include "Components/Velocity.hpp"
#include "Components/Position.hpp"
#include "SystemBase/MovementSystem.hpp"
#include "Components/Transform.hpp"
#include "Components/UserInput.hpp"

class Engine {
public:
    void run();
};
