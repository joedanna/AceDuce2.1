#ifndef MULTIGAME_H
#define MULTIGAME_H

#include "Game.h"
#include "Player.h"
#include <vector>

class Multigame : public Game {
private:
    vector<Player> players;
    int currentPlayerIndex;

public:
    Multigame(vector<string> playerNames, int initialBalancePerPlayer);
    void startGame() override;
    void nextPlayer();
};

#endif // MULTIGAME_H
