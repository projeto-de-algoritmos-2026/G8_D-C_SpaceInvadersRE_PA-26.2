#include <raylib.h>
#include "entities/fleet.cpp"

int main() {
    // Inicialização da janela
    const int screen_width = 1280;
    const int screen_height = 720;

    InitWindow(screen_width, screen_height, "Space Invaders: Dividir e Conquistar");
    SetTargetFPS(60);

    // Instancia o gestor da frota inimiga
    space_invaders::entities::Fleet enemy_fleet;

    // Configura uma frota com 10 linhas e 25 colunas (250 entidades na tela)
    // Parâmetros: (linhas, colunas, start_x, start_y, spacing_x, spacing_y)
    enemy_fleet.generate_fleet(10, 25, 100.0f, 60.0f, 45.0f, 35.0f);

    // Loop Principal
    while (!WindowShouldClose()) {

        // Atualização (Lógica)
        // TODO: Atualizar posições da frota e interagir com algoritmos de Divisão e Conquista

        // Renderização (Desenho)
        BeginDrawing();
        ClearBackground(BLACK);

        // Desenha as naves inimigas na tela
        enemy_fleet.draw();

        // Informação temporária na interface
        DrawText(TextFormat("Naves Ativas: %d", enemy_fleet.get_invaders().size()), 10, 10, 20, GREEN);
        DrawText("AGUARDANDO ALGORITMO MEDIANA DAS MEDIANAS...", 10, 35, 14, GRAY);
        
        EndDrawing();
    }

    // Desligar e limpar memória
    CloseWindow();
    return 0;
}