#include <iostream>
#include <cstdlib>
#include <string>
#include "../include/connect4.h"

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
    const std::string title = "\n -------------------------\n| Welcome to Connect 4! |\n -------------------------\n\n";
    std::string input;
    Connect4 c4;

    clearScreen();
    std::cout << title;
    c4.display_grid();

    unsigned selected_col = 0;

    while (!c4.is_game_over() && input != "q" && input != "Q") {
        while(selected_col >= 0 && selected_col < COLS) {
            std::cout << "Select a column (0-" << COLS-1 << "): ";
            std::cin >> input;
            selected_col = std::stoi(input);
        }
        
        c4.set_token(player_token, selected_col);
        c4.display_grid();
        c4.check_for_4(player_token, bot_token);

        if (c4.is_game_over()) {
            std::cout << "\n\nPlayer wins!\n\n";
            break;
        }

        c4.set_token(bot_token, c4.get_bot_move());
        c4.display_grid();
        c4.check_for_4(bot_token, player_token);
        
        if (c4.is_game_over()) {
            std::cout << "\n\nBot wins!\n\n";
            break;
        }
    }

    return 0;
}
