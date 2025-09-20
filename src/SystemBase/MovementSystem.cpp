#include "SystemBase/MovementSystem.hpp"


 void MovementSystem::update(EntityManager& em, float dt){
    for (Entity e:  entities){
        auto pos = em.getComponent<Position>(e);
        auto vel = em.getComponent<Velocity>(e);
        auto transofrm = em.getComponent<TransformComponent>(e);

        if(transofrm && vel){
            transofrm->position.x += vel->vx * dt;
            transofrm->position.y += vel->vy * dt;
        }
    }
}