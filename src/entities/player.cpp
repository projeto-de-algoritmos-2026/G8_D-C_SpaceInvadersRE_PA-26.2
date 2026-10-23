#include "entities/player.hpp"

namespace space_invaders::entities {
    Player::Player(float x, float y, float width, float height, float speed)
        : position{x, y}, size{width, height}, speed(speed), color(WHITE) {}

    void Player::update(float screen_width) {
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            position.x -= speed * dt;
        }
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            position.x += speed * dt;
        }

        float margin = 20.0f;
        if (position.x < margin) {
            position.x = margin;
        }
        if (position.x + size.x > screen_width - margin) {
            position.x = screen_width - margin - size.x;
        }

        // --- Disparo (Input e Cooldown) ---
        time_since_last_shot += dt;

        // IsKeyPressed regista apenas a primeira vez que a tecla desce
        if (IsKeyPressed(KEY_SPACE) && time_since_last_shot >= shoot_cooldown) {
            time_since_last_shot = 0.0f; // Reinicia o relógio

            Projectile p;
            p.x = position.x + (size.x / 2.0f) - (p.width / 2.0f); // Centraliza o tiro
            p.y = position.y;
            projectiles.push_back(p);
        }

        // --- Atualização de Balística e Reciclagem ---
        for (auto& p : projectiles) {
            p.update(dt);
        }

        // C++20: Apaga automaticamente do vetor (liberta memória) todos os projéteis não ativos
        std::erase_if(projectiles, [](const Projectile& p) { return !p.is_active; });
    }

    void Player::draw() const {
        DrawRectangleRec(get_rect(), color);
        for (const auto& p : projectiles) {
            p.draw();
        }
    }
}