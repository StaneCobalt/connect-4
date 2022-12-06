// Connect4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include "connect4.h"
using namespace std;

#ifdef _WIN32
void clearScreen() {
    system("CLS");
}

#elif _APPLE_
void clearScreen() {
    system("clear");
}

#elif _linux_
void clearScreen() {
    system("clear & clear");
}

#else
void clearScreen() {
    std::cout << "\n";
}

#endif

int main() {
    const string title = "\n -----------\n| CONNECT 4 |\n -----------\n\n";
    string input;
    Connect4 c4;
    c4.init_grid();

    while (!c4.is_game_over()) {
        clearScreen();
        cout << title;
        c4.display_grid();

        unsigned selected_col = 0;

        cout << "Select a column (0-" << COLS - 1 << "): ";
        cin >> input;
        if (input == "q" || input == "Q") {
            cout << "Quitting...\n";
            break;
        }
        selected_col = stoi(input);

        bool tokenSet = c4.set_token(player_token, selected_col);

        while (!tokenSet) {
            cout << "Select a column (0-" << COLS - 1 << "): ";
            cin >> input;
            if (input == "q" || input == "Q") {
                cout << "Quitting...\n";
                break;
            }
            selected_col = stoi(input);

            tokenSet = c4.set_token(player_token, selected_col);
        }

        c4.check_for_4(player_token, bot_token);

        if (c4.is_game_over()) {
            clearScreen();
            cout << title;
            c4.display_grid();
            cout << "\n\nPlayer wins!\n\n";
            break;
        }

        c4.set_token(bot_token, c4.get_bot_move());
        c4.check_for_4(bot_token, player_token);

        if (c4.is_game_over()) {
            clearScreen();
            cout << title;
            c4.display_grid();
            cout << "\n\nBot wins!\n\n";
            break;
        }
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
