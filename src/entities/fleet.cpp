#include "entities/fleet.hpp"

#include "raylib.h"

namespace space_invaders::entities {

    Fleet::Fleet() {}

    void Fleet::generate_fleet(int rows, int cols, float start_x, float start_y, float spacing_x, float spacing_y) {
        // LImpeza e reserva de memória
        invaders.clear();
        invaders.reserve(rows * cols);

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                Invader ship;
                ship.x = start_x + (c * spacing_x);
                ship.y = start_y + (r * spacing_y);
                ship.is_alive = true;
                // define o tipo para linha r
                ship.type = static_cast<InvaderType>(r % 3);

                invaders.push_back(ship);
            }
        }
    }

    void Fleet::update(float screen_width) {
        if (invaders.empty()) return;

        float dt = GetFrameTime();
        float dx = speed_x * direction * dt;

        bool hit_edge = false;
        float margin = 20.0f;

        // Assume que a largura é igual para todas as naves
        float invader_width = invaders.front().width;

        // 1. Verificação de limites olhando apenas para as naves VIVAS
        for (const auto& ship : invaders) {
            if (!ship.is_alive) continue;

            if (direction == 1 && (ship.x + invader_width + dx > screen_width - margin)) {
                hit_edge = true;
                break;
            }
            else if (direction == -1 && (ship.x + dx < margin)) {
                hit_edge = true;
                break;
            }
        }

        // 2. Aplicação do movimento (Shift Down ou Movimento Lateral contínuo)
        if (hit_edge) {
            direction *= -1; // Inverte o eixo X
            for (auto& ship : invaders) {
                ship.y += drop_distance;
            }
        } else {
            for (auto& ship : invaders) {
                ship.x += dx;
            }
        }
    }

    void Fleet::draw() const {
        for (const auto& ship : invaders) {
            ship.draw();
        }
    }

    std::vector<Invader>& Fleet::get_invaders() {
        return invaders;
    }
}
