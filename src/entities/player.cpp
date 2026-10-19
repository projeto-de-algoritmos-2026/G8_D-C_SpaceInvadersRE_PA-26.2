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
    }

    void Player::draw() const {
        DrawRectangleRec(get_rect(), color);
    }
}