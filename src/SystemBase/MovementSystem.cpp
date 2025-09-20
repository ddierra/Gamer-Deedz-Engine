#include "SystemBase/MovementSystem.hpp"


 void MovementSystem::update(EntityManager& em, float dt){
    for (Entity e:  entities){
        auto pos = em.getComponent<Position>(e);
        auto vel = em.getComponent<Velocity>(e);
        if(pos && vel){
            for(auto& entity : em.getEntitiesWith<TransformComponent>()){
                auto& transform = em.getComponent<TransformComponent>();
                if(UserInput.up){

                }
            }
            pos->x += vel->vx * dt;
            pos->y =+ vel->vy * dt;
        }
    }
}