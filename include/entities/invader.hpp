
#pragma once
namespace space_invaders::entities {

    enum class InvaderType {
        // valores temporarios sera preciso definir os tipos depois
        ALPHA,
        BETA,
        GAMMA
    };


    struct Invader {
        float x;
        float y;
        bool is_alive;
        InvaderType type;
        // valores temporarios
        float width = 30.0f;
        float height = 20.0f;
    };

}
