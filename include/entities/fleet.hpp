#pragma once
#include <vector>
#include "entities/invader.hpp"

namespace space_invaders::entities {

    class Fleet {
    private:
        std::vector<Invader> invaders;
        float speed_x = 100.0f;       // Velocidade horizontal em pixels por segundo
        int direction = 1;            // 1 para direita, -1 para esquerda
        float drop_distance = 20.0f;  // Quantidade de pixels que a frota desce ao bater na borda

    public:
        Fleet();
        ~Fleet() = default;
        void generate_fleet(int rows, int cols, float start_x, float start_y, float spacing_x, float spacing_y);

        void update(float screen_width);

        void draw() const;


        std::vector<Invader>& get_invaders();
    };

}

