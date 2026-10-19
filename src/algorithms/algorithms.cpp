#include "algorithms/algorithms.hpp"

namespace space_invaders::algorithms {

    entities::Invader* find_commander(std::vector<entities::Invader>& fleet) {
        if (fleet.empty()) return nullptr;
        
        //Retorna a nave que está no meio do vetor em memória, isso é apenas um stub
        int mid_index = fleet.size() / 2;
        return &fleet[mid_index];
    }

    std::pair<entities::Invader*, entities::Invader*> find_closest_pair(std::vector<entities::Invader>& fleet) {
        if (fleet.size() < 2) return {nullptr, nullptr};
        
        //  Retorna a primeira nave e a decima do vetor, isso é temporario
        return {&fleet[0], &fleet[9]};
    }

}