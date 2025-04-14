//
// Created by admini
#include "Deck.h"

Deck::Deck() {
    vector<string> suits = {"Club's", "Spade's", "Heart's", "Diamond's"};
    vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    vector<int> values = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    for (const auto &suit : suits) {
        for (size_t i = 0; i < ranks.size(); ++i) {
            cards.push_back(Card(suit, ranks[i], values[i]));
        }
    }

    shuffle(cards.begin(), cards.end(), default_random_engine(time(nullptr)));
}

Card Deck::dealCard() {
    Card card = cards.back();
    cards.pop_back();
    return card;
}
