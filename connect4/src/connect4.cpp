#include <iostream>
#include "connect4.h"
using namespace std;

void Connect4::init_grid() {
	for (unsigned i = 0; i < ROWS; i++) {
		for (unsigned j = 0; j < COLS; j++) {
			display[i][j] = empty_token;
		}
	}
}

void Connect4::display_grid() {
	for (unsigned i = ROWS; i > 0; i--) {
		for (unsigned j = 0; j < COLS; j++) {
			std::cout << display[i-1][j] << ' ';
		}
		cout << '\n';
	}
	int turn = turn_count / 2;
	cout << "\nTurn:" << turn << '\n';
}

bool Connect4::is_col_available(unsigned col) {
	return display[ROWS-1][col] == empty_token;
}

bool Connect4::set_token(char token, unsigned col) {
	if (col >= COLS) {
		cout << "Column is out of bounds";
		return false;
	}
	else if (!is_col_available(col)) {
		cout << "Column is full.";
		return false;
	}
	
	for (unsigned i = 0; i < ROWS; i++) {
		if (display[i][col] == empty_token) {
			display[i][col] = token;
            turn_count++;
			return true;
		}
	}
}

void Connect4::check_for_4(char token1, char token2) {	
    if(turn_count < 7) return;

	unsigned count = 0;
	
	// check vertically
	for (unsigned i = 0; i < COLS; i++) {
		for (unsigned j = 0; j < ROWS; j++) {
			if (count == 4) {
				game_over = true;
				return;
			}
			else if (display[j][i] == token1)
				count++;
			else
				count = 0;
		}
	}
	
	count = 0;
	// check horizontally
	for (unsigned i = 0; i < ROWS; i++) {
		for (unsigned j = 0; j < COLS; j++) {
			if (count == 4) {
				game_over = true;
				return;
			}
			else if (display[i][j] == token1)
				count++;
			else
				count = 0;
		}
	}
	
	// todo: check diagonally
}

unsigned Connect4::get_bot_move() {
    unsigned bot_move = rand() % COLS;

	while(!is_col_available(bot_move)) {
		bot_move = rand() % COLS;
	}

	return bot_move;
}
