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

        // Acumula o tempo que passou desde o último frame
        float dt = GetFrameTime();
        move_timer += dt;

        // Só vai movimentar quando der o intervalo
        if (move_timer >= move_interval) {
            move_timer = 0.0f; // Reinicia o timer para o próximo salto

            float dx = step_x * direction;
            bool hit_edge = false;
            float margin = 20.0f;
            float invader_width = invaders.front().width;

            // 1. Verifica se a frota antingiu a borda
            // direction = 1 = mover pra direita e = -1 é o mesmo que mexer pra esquerda
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

            // Salto da nave
            if (hit_edge) {
                direction *= -1;
                for (auto& ship : invaders) {
                    ship.y += drop_distance;
                }
            } else {
                for (auto& ship : invaders) {
                    ship.x += dx;
                }
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
