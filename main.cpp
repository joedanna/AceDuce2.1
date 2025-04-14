#include "MultiGame.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> playerNames;
    int numPlayers; // Default number of players

    cout << "Welcome to Multiplayer Inbetween!";
    cout << "\nEnter Many PLayers Are Playing: ";
    cin >> numPlayers;
    cout << "\nThe Rules: \n "; // The RUles of the Game
    cout << "1. You get two cards." << endl;
    cout << " 2. You will place a bet that can be no greater than the pot. ";
    cout << "\n 3. You are betting on if the next card displayed will be In between the two cards you are presented.";
    cout << "\n 4. The Pot starts with $100. ";
    cout << "\n 5. if you lose your bet is added to the Pot.";
    cout << "\n 6. if you win you get your bet back and that amount out of the Pot.";
    cout << "\n 7. Ace = 14, Two = 2. ";
    cout << "\n 8. The Game will end when the Pot is empty";
    cout << "\n 9. If next card is the same type of card the Pot will double, and you lose.";
    cout <<" \n 10. If a Player Runs out of money they are Out of the Game.";
    cout << "\n 11. Each Player will get turn and then it will move to the next Player. ";
    cout <<" \n Each player will enter their name.\n";

    for (int i = 1; i <= numPlayers; ++i) {
        string name;
        cout << "Enter name for Player " << i << ":";

        // Read input propery leftover newline characters
        cin.ignore();
        getline(cin, name); // Use getline to allow for names with spaces
        playerNames.push_back(name); // Add the name to the vector

    }

    int initialBalancePerPlayer ; // Starting balance for each player
    cout << "ENTER STARTING BALNCE: ";
    cin >> initialBalancePerPlayer;

    Multigame multiplayerGame(playerNames, initialBalancePerPlayer);
    multiplayerGame.startGame();

    return 0;
}
