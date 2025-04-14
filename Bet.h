#ifndef BET_H
#define BET_H

#include "AbstractBet.h"
#include <iostream>
using namespace std;

class Bet : public AbstractBet {
public:
    int placeBet() override {
        int bet;
        cout << "Place your bet: ";
        cin >> bet;
        return bet;
    }
};

#endif // BET_H
