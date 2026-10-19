#pragma once
#include <vector>
#include <utility>
#include "entities/invader.hpp"

namespace space_invaders::algorithms {

    // Retorna um ponteiro para a nave comandante (Alvo para a Mediana das Medianas)
    entities::Invader* find_commander(std::vector<entities::Invader>& fleet);

    // Retorna um par de ponteiros para as duas naves mais próximas (Par de Pontos)
    std::pair<entities::Invader*, entities::Invader*> find_closest_pair(std::vector<entities::Invader>& fleet);

}