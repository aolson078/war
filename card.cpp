#include "card.h"
#include <iostream>
Card::Card(Suit _suit, Value _value) : suit{_suit}, value{_value}
{
}
bool Card::sameSuit(const Card &other)
{
    return suit == other.suit;
}
bool Card::sameValue(const Card &other)
{
    return value == other.value;
}
bool operator==(const Card &lhs, const Card &rhs)
{
    return lhs.value == rhs.value;
}
bool operator<(const Card &lhs, const Card &rhs)
{
    return lhs.value < rhs.value;
}
bool operator>(const Card &lhs, const Card &rhs)
{
    return lhs.value > rhs.value;
}
std::ostream &operator<<(std::ostream &s, const Card &c)
{
    switch (c.value)
    {
    case Value::Two:
        s << "Two";
        break;
    case Value::Three:
        s << "Three";
        break;
    case Value::Four:
        s << "Four";
        break;
    case Value::Five:
        s << "Five";
        break;
    case Value::Six:
        s << "Six";
        break;
    case Value::Seven:
        s << "Seven";
        break;
    case Value::Eight:
        s << "Eight";
        break;
    case Value::Nine:
        s << "Nine";
        break;
    case Value::Ten:
        s << "Ten";
        break;
    case Value::Jack:
        s << "Jack";
        break;
    case Value::Queen:
        s << "Queen";
        break;
    case Value::King:
        s << "King";
        break;
    case Value::Ace:
        s << "Ace";
        break;
    }
    s << " of ";
    switch (c.suit)
    {
    case Suit::Spade:
        s << "Spades";
        break;
    case Suit::Club:
        s << "Clubs";
        break;
    case Suit::Diamond:
        s << "Diamonds";
        break;
    case Suit::Heart:
        s << "Hearts";
        break;
    }
    return s;
}
