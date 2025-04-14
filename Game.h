#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Bet.h"
#include "Pot.h"

class Game {
protected:
    Deck deck;
    Pot pot;

public:
    virtual void startGame() = 0; // Pure virtual function
};

#endif // GAME_H

