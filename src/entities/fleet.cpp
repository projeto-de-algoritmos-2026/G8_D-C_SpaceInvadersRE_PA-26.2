#include "entities/fleet.hpp"

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

    void Fleet::draw() const {
        for (const auto& ship : invaders) {
            ship.draw();
        }
    }

    std::vector<Invader>& Fleet::get_invaders() {
        return invaders;
    }
}