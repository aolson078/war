#include <random>
#include <queue>
#include <vector>
#include "deck.h"

enum class WinState { winA, winB, tie, ongoing };
enum class PlayState { normal, warDown, warUp };


class War;

class War {
private:
    std::default_random_engine& gen;
    Deck deck;
    std::queue<Card*> playerA, playerB;
    std::vector<Card*> middle;
    PlayState playState;

public:
    War(std::default_random_engine& _gen);
    WinState playRound();
};