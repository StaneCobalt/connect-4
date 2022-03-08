#include <iostream>
#include <cstdlib>
#include <string>
#include "connect4.h"
using namespace std;

#ifdef _WIN32
	void clearScreen(){
		system("CLS");
	}

#elif _APPLE_
	void clearScreen(){
		system("clear");
	}

#elif _linux_
	void clearScreen(){
		system("clear & clear");
	}

#else
	void clearScreen(){
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

        cout << "Select a column (0-" << COLS-1 << "): ";
        cin >> input;
        if(input == "q" || input == "Q") {
            cout << "Quitting...\n";
            break;
        }
        selected_col = stoi(input);
        
        bool tokenSet = c4.set_token(player_token, selected_col);

        while(!tokenSet) {
            cout << "Select a column (0-" << COLS-1 << "): ";
            cin >> input;
            if(input == "q" || input == "Q") {
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
