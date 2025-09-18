#include "SystemBase/MovementSystem.hpp"

 void MovementSystem::update(EntityManager& em, float dt){
    for (Entity e:  entities){
        auto pos = em.getComponent<Position>(e);
        auto vel = em.getComponent<Velocity>(e);
        if(pos && vel){
            pos->x += vel->vx * dt;
            pos->y =+ vel->vy * dt;
        }
    }
}