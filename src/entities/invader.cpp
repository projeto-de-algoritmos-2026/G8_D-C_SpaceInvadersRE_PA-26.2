#include "entities/invader.hpp"
#include <raylib.h>

namespace space_invaders::entities {

    void Invader::draw() const {

        if (!is_alive) return;

        Color color = WHITE; // cor padrão é branco

        if (type == InvaderType::ALPHA) color = RED;

        else if (type == InvaderType::BETA) color = ORANGE;
        else if (type == InvaderType::GAMMA) color = YELLOW;

        DrawRectangle((int)x, (int)y, (int)width, (int)height, color);
    }

}
