#include <ostream>

#ifndef CARD_H
#define CARD_H

enum class Suit
{
    Spade,
    Club,
    Diamond,
    Heart
};
enum class Value
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};
class Card
{
private:
    const Suit suit;
    const Value value;
public:
    Card(Suit _suit, Value _value);
    bool sameSuit(const Card &other);
    bool sameValue(const Card &other);
    friend bool operator==(const Card &lhs, const Card &rhs);
    friend bool operator<(const Card &lhs, const Card &rhs);
    friend bool operator>(const Card &lhs, const Card &rhs);
    friend std::ostream &operator<<(std::ostream &s, const Card &c);
};

#endif