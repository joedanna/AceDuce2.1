#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

class Deck {
private:
    vector<Card> cards;

public:
    Deck();

    Card dealCard();

    size_t size() const { return cards.size(); }
};

#endif // DECK_H
