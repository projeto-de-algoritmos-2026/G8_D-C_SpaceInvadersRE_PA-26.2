#pragma once
#include <raylib.h>

namespace space_invaders::entities {

    struct Projectile {
        float x;
        float y;
        float width = 4.0f;
        float height = 15.0f;
        float speed = 600.0f;
        bool is_active = true;

        void update(float dt);
        void draw() const;
    };

}