#include <vector>
#include <memory>
#include <random>
#include <stack>
#include "card.h"

class Deck;

class Deck
{
private:
    std::default_random_engine& gen;
    std::vector<std::unique_ptr<Card>> cards;
    std::stack<Card*> drawPile;
public:
    Deck(std::default_random_engine& _gen);
    void reshuffle();
    Card* draw();
    bool isEmpty() const { return drawPile.empty(); }
};
