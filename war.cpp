#include <iostream>
#include "war.h"
#include <algorithm>

War::War(std::default_random_engine &_gen) : gen{_gen}, deck{_gen}
{
    while (!deck.isEmpty())
    {
        playerA.push(deck.draw());
        playerB.push(deck.draw());
    }
}

WinState War::playRound()
{
    if (playerA.empty())
    {
        return WinState::winB;
    }
    else if (playerB.empty())
    {
        return WinState::winA;
    }

    Card *cardA = playerA.front();
    playerA.pop();
    Card *cardB = playerB.front();
    playerB.pop();

    std::cout << "Player A draws " << *cardA << std::endl;
    std::cout << "Player B draws " << *cardB << std::endl;

    while (*cardA == *cardB)
    {
        middle.push_back(cardA);
        middle.push_back(cardB);

        if (playerA.empty() || playerB.empty())
        {
            break;
        }

        middle.push_back(playerA.front());
        playerA.pop();
        middle.push_back(playerB.front());
        playerB.pop();

        if (playerA.empty() || playerB.empty())
        {
            break;
        }

        cardA = playerA.front();
        playerA.pop();
        cardB = playerB.front();
        playerB.pop();
    }

    std::shuffle(middle.begin(), middle.end(), gen);

    if (cardA > cardB)
    {
        playerA.push(cardA);
        playerA.push(cardB);
        while (!middle.empty())
        {
            playerA.push(middle.back());
            middle.pop_back();
        }
    }
    else if (cardB > cardA)
    {
        playerB.push(cardA);
        playerB.push(cardB);
        while (!middle.empty())
        {
            playerB.push(middle.back());
            middle.pop_back();
        }
    }
    else
    {
        middle.push_back(cardA);
        middle.push_back(cardB);
        playRound();
    }

    std::cout << "Player A has " << playerA.size() << " cards left." << std::endl;
    std::cout << "Player B has " << playerB.size() << " cards left." << std::endl;

    if (!playerA.empty() && !playerB.empty())
    {
        return WinState::ongoing;
    }
    else if (playerA.empty())
    {
        return WinState::winB;
    }
    else
    {
        return WinState::winA;
    }
}