#include <raylib.h>

int main() {
    // Inicialização da janela
    const int screen_width = 1280;
    const int screen_height = 720;
    
    InitWindow(screen_width, screen_height, "Space Invaders: Dividir e Conquistar");
    SetTargetFPS(60);

    // Loop Principal
    while (!WindowShouldClose()) {
        
        // Atualização (Lógica)
        // TODO: Atualizar frota e verificar quebra de escudo
        
        // Renderização (Desenho)
        BeginDrawing();
        ClearBackground(BLACK);
        
        DrawText("SISTEMA ONLINE. AGUARDANDO FROTA INIMIGA...", 350, 340, 20, GREEN);
        
        EndDrawing();
    }

    // Desligar e limpar memória
    CloseWindow();
    return 0;
}