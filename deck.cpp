#include "deck.h"
#include "card.h"
#include <stack>
#include <memory>
#include <algorithm>

Deck::Deck(std::default_random_engine &_gen) : gen{_gen}
{
    constexpr auto suitVec = std::array<Suit, 4>{
        Suit::Club, Suit::Diamond, Suit::Heart, Suit::Spade};
    constexpr auto valueVec = std::array<Value, 13>{
        Value::Two, Value::Three, Value::Four, Value::Five,
        Value::Six, Value::Seven, Value::Eight, Value::Nine,
        Value::Ten, Value::Jack, Value::Queen, Value::King, Value::Ace};
    for (auto ivalue : valueVec)
    {
        for (auto isuit : suitVec)
        {
            cards.push_back(std::make_unique<Card>(isuit, ivalue));
        }
    }
    reshuffle();
}

void Deck::reshuffle()
{
    std::shuffle(cards.begin(), cards.end(), gen);
    std::stack<Card *> tmpStack;
    for (auto &card : cards)
    {
        tmpStack.push(card.get());
    }
    drawPile.swap(tmpStack);
}

Card *Deck::draw()
{
    if (drawPile.empty())
    {
        return nullptr;
    }
    else
    {
        Card *temp = drawPile.top();
        drawPile.pop();
        return temp;
    }
}