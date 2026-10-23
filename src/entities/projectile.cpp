#include "entities/projectile.hpp"

namespace space_invaders::entities {

    void Projectile::update(float dt) {
        if (!is_active) return;
        
        y -= speed * dt; // velocidade diminui conforme avança
        
        //Se sair da tela será deletado
        if (y + height < 0) {
            is_active = false;
        }
    }

    void Projectile::draw() const {
        if (!is_active) return;
        DrawRectangle((int)x, (int)y, (int)width, (int)height, YELLOW);
    }

}