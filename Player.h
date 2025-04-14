#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
private:
    string name;
    int balance;

public:
    Player(string playerName, int initialBalance) : name(playerName), balance(initialBalance) {}
    string getName() const { return name; }
    int getBalance() const { return balance; }
    void adjustBalance(int amount) { balance += amount; }
};

#endif // PLAYER_H
