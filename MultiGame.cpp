#include "MultiGame.h"
#include <iostream>
using namespace std;

Multigame::Multigame(vector<string> playerNames, int initialBalancePerPlayer) : currentPlayerIndex(0) {
    for (const auto &name : playerNames) {
        players.push_back(Player(name, initialBalancePerPlayer));
    }
}

void Multigame::nextPlayer() {
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}

void Multigame::startGame() {
    cout << "The pot starts at $100. Let’s begin!\n";

    while (true) {
        if (pot.potValue <= 0) {
            cout << "The pot is empty. Game over!\n";
            break;
        }

        if (deck.size() < 3) {
            cout << "Not enough cards left in the deck. Reshuffling...\n";
            deck = Deck();
        }

        Player &currentPlayer = players[currentPlayerIndex];
        cout << "\nCurrent turn: " << currentPlayer.getName() << "\n";
        cout << "Current balance: $" << currentPlayer.getBalance() << "\n";
        cout << "Shared pot: $" << pot.potValue << "\n";

        Card card1 = deck.dealCard();
        Card card2 = deck.dealCard();
        cout << "First card: " << card1 << "\n";
        cout << "Second card: " << card2 << "\n";

        if (card1.getValue() > card2.getValue()) {
            swap(card1, card2);
        }

        Bet bet;
        int playerBet = bet.placeBet();

        if (playerBet > currentPlayer.getBalance()) {
            cout << "You cannot bet more than your balance! Please try again.\n";
            continue;
        }

        Card middleCard = deck.dealCard();
        cout << "Middle card: " << middleCard << "\n";

        if (middleCard.getValue() == card1.getValue() || middleCard.getValue() == card2.getValue()) {
            cout << "You hit Post! You must add double your bet to the pot.\n";
            pot.adjustPot(+2 * playerBet);
            currentPlayer.adjustBalance(-2 * playerBet);
        } else if (middleCard.getValue() > card1.getValue() && middleCard.getValue() < card2.getValue()) {
            cout << "You win! The pot decreases by your bet amount.\n";
            pot.adjustPot(-playerBet);
            currentPlayer.adjustBalance(+playerBet);
        } else {
            cout << "You lose! Your bet is added to the pot.\n";
            pot.adjustPot(playerBet);
            currentPlayer.adjustBalance(-playerBet);
        }

        if (pot.potValue <= 0) {
            cout << "The pot is empty. Game over!\n";
            break;
        }

        if (currentPlayer.getBalance() <= 0) {
            cout << currentPlayer.getName() << " has run out of money! They are out of the game.\n";
            players.erase(players.begin() + currentPlayerIndex);
            if (players.empty()) {
                cout << "All players are out. Game over!\n";
                break;
            }
            currentPlayerIndex %= players.size();
            continue;
        }

        nextPlayer();

        char choice;
        cout << "\nDo you want to continue the game? (y/n): ";
        cin >> choice;
        if (choice != 'y') break;
    }

    cout << "Thank you for playing! Final pot: $" << pot.potValue << "\n";
}

