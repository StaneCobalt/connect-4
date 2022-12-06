#include <iostream>
#include "connect4.h"
#include <random>
#include <time.h>
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
			std::cout << display[i - 1][j] << ' ';
		}
		cout << '\n';
	}
	int turn = turn_count / 2;
	cout << "\nTurn:" << turn << '\n';
}

bool Connect4::is_col_available(unsigned col) {
	return display[ROWS - 1][col] == empty_token;
}

bool Connect4::set_token(char token, unsigned col) {
	try {
		if (col >= COLS) {
			cout << "Column is out of bounds.\n";
			return false;
		}
		else if (!is_col_available(col)) {
			cout << "Column is full.\n";
			return false;
		}

		for (unsigned i = 0; i < ROWS; i++) {
			if (display[i][col] == empty_token) {
				display[i][col] = token;
				turn_count++;
				return true;
			}
		}

		cout << "Unknown error. Try again.\n";
		return false;
	}
	catch (const char* message) {
		std::cerr << "Error in set_token!\n" << message << endl;
		return false;
	}
}

void Connect4::check_for_4(char token1, char token2) {
	if (turn_count < 7) return;

	try {
		unsigned count = 0, threshold = 3, offset = 0, index = 0;

		// check vertically
		for (unsigned i = 0; i < COLS; i++) {
			for (unsigned j = 0; j < ROWS; j++) {
				if (display[j][i] == token1) {
					count++;
					if (count == 4) {
						game_over = true;
						return;
					}
				}
				else {
					count = 0;
				}
			}
		}

		// check horizontally
		count = 0;
		for (unsigned i = 0; i < ROWS; i++) {
			for (unsigned j = 0; j < COLS; j++) {
				if (display[i][j] == token1) {
					count++;
					if (count == 4) {
						game_over = true;
						return;
					}
				}
				else {
					count = 0;
				}
			}
		}

		// check diagonally left to right (lower)
		count = 0;
		while (offset < threshold) {
			for (int i = 0; i + offset < ROWS; i++) {
				if (display[i + offset][i] == token1) {
					count++;
					if (count == 4) {
						game_over = true;
						return;
					}
				}
				else {
					count = 0;
				}
			}
			offset++;
		}

		// check diagonally left to right (upper)
		offset = 0;
		count = 0;
		while (offset < threshold) {
			for (unsigned i = 0; i < ROWS - offset; i++) {
				if (display[i][i + offset + 1] == token1) {
					count++;
					if (count == 4) {
						game_over = true;
						return;
					}
				}
				else {
					count = 0;
				}
			}
			offset++;
		}

		// check diagonally right to left (lower)
		offset = 1;
		count = 0;
		while (offset <= threshold) {
			unsigned col = ROWS - offset;

			for (unsigned i = 0; i < ROWS - offset; i++) {
				if (display[i][col] == token1) {
					count++;
					if (count == 4) {
						game_over = true;
						return;
					}
				}
				else {
					count = 0;
				}
				col--;
			}

			offset++;
		}

		// check diagonally right to left (upper)
		offset = 0;
		count = 0;
		while (offset < threshold) {
			unsigned col = COLS - 1;

			for (int i = offset; i < ROWS; i++) {
				if (display[i][col] == token1) {
					count++;
					if (count == 4) {
						game_over = true;
						return;
					}
				}
				else {
					count = 0;
				}
				col--;
			}

			offset++;
		}
	}
	catch (const char* message) {
		std::cerr << "Error in check_for_4!\n" << message << endl;
	}
}

unsigned Connect4::get_bot_move() {
	std::default_random_engine generator { static_cast<long unsigned int>(time(0)) };
	std::uniform_int_distribution<unsigned> distribution(0, COLS - 1);
	unsigned bot_move = distribution(generator);

	while (!is_col_available(bot_move)) {
		std::default_random_engine generator { static_cast<long unsigned int>(time(0)) };
		std::uniform_int_distribution<unsigned> distribution(0, COLS - 1);
		bot_move = distribution(generator); bot_move = rand() % COLS;
	}

	return bot_move;
}
