#pragma once
#include <vector>
#include "entities/invader.hpp"

namespace space_invaders::entities {

    class Fleet {
    private:
        std::vector<Invader> invaders;

    public:
        Fleet();
        ~Fleet() = default;
        void generate_fleet(int rows, int cols, float start_x, float start_y, float spacing_x, float spacing_y);


        void draw() const;


        std::vector<Invader>& get_invaders();
    };

}

