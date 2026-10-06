# G8_D-C_SpaceInvadersRE_PA-26.2

# || 👾 Space Invaders: Dividir e Conquistar 👾 ||

Este projeto irá ser uma recriação moderna e caótica do clássico *Space Invaders*, desenvolvido em **C++** com a biblioteca **Raylib**. O objetivo principal é demonstrar a aplicação prática do paradigma de **Dividir e Conquistar** para otimizar o desempenho ao processar frotas massivas de inimigos.

## > --- | Mecânicas e Algoritmos | --- <

O jogo utiliza dois algoritmos clássicos de Divisão e Conquista para resolver gargalos computacionais geométricos e estatísticos em tempo real:

### 1. Quebra de Escudo (Mediana das Medianas)
* **O Problema:** A frota inimiga está protegida por um escudo impenetrável. Para desativá-lo, o jogador deve focar o tiro na "Nave Comandante", que é dinamicamente o centro de massa da frota (a mediana das coordenadas X).
* **A Solução:** Em vez de ordenar o vetor de naves a cada *frame* para encontrar o centro, utilizamos o algoritmo da **Mediana das Medianas** para encontrar o alvo exato com garantia de tempo linear **O(n)** no pior caso, evitando quedas na taxa de fotogramas.

### 2. Reação em Cadeia Letal (Par de Pontos mais Próximos)
* **O Problema:** Após a queda do escudo, o jogador pode disparar um raio elétrico. Este raio deve atingir a área mais densa do enxame inimigo para maximizar o dano em cadeia.
* **A Solução:** Calcular a distância entre todas as naves através de força bruta custaria tempo quadrático. Utilizamos o algoritmo do **Par de Pontos mais Próximos** para varrer o enxame e encontrar as duas naves mais próximas entre si em **O(n log n)**.

## > --- | Tecnologias a Serem Utilizadas | --- <
* **Linguagem:** C++
* **Gráficos e Janela:** Raylib
* **Build System:** CMake

## > --- | Como vai funcionar a Compilação e Executação | --- <

### Pré-requisitos
* Compilador C++ (ex: GCC ou Clang)
* CMake
* Raylib (será obtida via FetchContent no CMake)

### Compilação (Linux)
Abra o terminal na raiz do projeto e execute:
```bash
mkdir build
cd build
cmake ..
make
./space_invaders_dc
