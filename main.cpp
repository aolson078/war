#include "war.h"
#include <iostream>
#include <random>
#include <chrono>

int main() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	auto gen = std::default_random_engine{seed};

        auto war = War{gen};

        auto ws = WinState::ongoing;
        int countRounds = 0;
        while (ws == WinState::ongoing) {
            ws = war.playRound();
            ++countRounds;
        }
        std::cout << countRounds << " rounds total." << std::endl;

        return 0;
}