#include <iostream>
#include "../include/connect4.h"

using namespace std;
using std::cout;

void Connect4::display_grid() {
	for (unsigned i = 0; i < ROWS; i++) {
		for (unsigned j = 0; j < COLS; j++) {
			std::cout << this->display[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool Connect4::is_col_available(unsigned col) {
	return this->display[ROWS-1][col] == empty_token;
}

void Connect4::set_token(char token, unsigned col) {
	if (col >= COLS) cout << "Column is out of bounds"; return;
	if (!is_col_available(col)) cout << "Column is full."; return;
	
	for (unsigned i = 0; i < ROWS; i++) {
		if (this->display[i][col] == empty_token) {
			this->display[i][col] = token;
            this->turn_count++;
			return;
		}
	}
}

void Connect4::check_for_4(char token1, char token2) {	
    if(this->turn_count < 8) return;

	unsigned count = 0;

	// check vertically
	for (unsigned i = 0; i < COLS; i++) {
		for (unsigned j = 0; j < ROWS; j++) {
			if (count == 4) {
				game_over = true;
				return;
			}
			else if (this->display[j][i] == token1)
				count++;
			else if (this->display[j][i] == token2 || this->display[j][i] == empty_token)
				count = 0;
		}
	}
	
	// check horizontally
	for (unsigned i = 0; i < ROWS; i++) {
		for (unsigned j = 0; j < COLS; j++) {
			if (count == 4) {
				game_over = true;
				return;
			}
			else if (this->display[i][j] == token1)
				count++;
			else if (this->display[i][j] == token2)
				count = 0;
			else if (this->display[j][i] == token2 || this->display[j][i] == empty_token)
				count = 0;
		}
	}
	
	// check diagonally L->R
	for (unsigned i = 0; i < ROWS; i++) {
		for (unsigned j = 0; j < COLS; j++) {
			
		}
	}
}

unsigned Connect4::get_bot_move() {
    return rand() % COLS;
}
