#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
using namespace std;

class Card {
private:
    string suit;
    string rank;
    int value;

    friend void displayCardDetails(const Card &card); // Friend Function

public:
    Card(string s, string r, int v) : suit(s), rank(r), value(v) {}
    string getSuit() const { return suit; }
    string getRank() const { return rank; }
    int getValue() const { return value; }

    friend ostream &operator<<(ostream &os, const Card &card) { // Operator Overloading
        os << card.rank << " of " << card.suit;
        return os;
    }
};

inline void displayCardDetails(const Card &card) {
    cout << "Card Details: " << card.rank << " of " << card.suit << ", Value: " << card.value << endl;
}

#endif // CARD_H

