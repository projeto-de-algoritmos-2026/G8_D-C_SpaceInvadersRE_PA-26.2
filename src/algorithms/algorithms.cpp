#include "algorithms/algorithms.hpp"

namespace space_invaders::algorithms {

    entities::Invader* find_commander(std::vector<entities::Invader>& fleet) {
        if (fleet.empty()) return nullptr;
        
        //Retorna a nave que está no meio do vetor em memória
        int mid_index = fleet.size() / 2;
        return &fleet[mid_index];
    }

    std::pair<entities::Invader*, entities::Invader*> find_closest_pair(std::vector<entities::Invader>& fleet) {
        if (fleet.size() < 2) return {nullptr, nullptr};
        
        //  Retorna as duas primeiras naves do vetor
        return {&fleet[0], &fleet[1]};
    }

}