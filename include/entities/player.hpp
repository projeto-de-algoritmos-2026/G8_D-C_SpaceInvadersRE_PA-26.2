#pragma once
#include <raylib.h>
#include <vector>
#include "projectile.hpp"

namespace space_invaders::entities {

class Player {
private:
    Vector2 position;
    Vector2 size;
    float speed;
    Color color;
    // --- Sistema de Armamento ---
    std::vector<Projectile> projectiles;
    float shoot_cooldown = 0.4f; // Tempo em segundos entre disparos
    float time_since_last_shot = 0.0f;

public:
    Player(float x, float y, float width, float height, float speed);

    void update(float screen_width);
    void draw() const;

    Vector2 get_position() const { return position; }
    Rectangle get_rect() const { return { position.x, position.y, size.x, size.y }; }
};

} 