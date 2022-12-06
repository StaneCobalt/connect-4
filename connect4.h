#pragma once
#include <array>

// connect4 = 7wx6h grid

const unsigned COLS = 7;
const unsigned ROWS = 6;
const char empty_token = 'O';
const char player_token = 'X';
const char bot_token = '*';

class Connect4 {
private:
	std::array<std::array<char, COLS>, ROWS> display;
	unsigned turn_count;
	bool game_over = false;
public:
	Connect4() { turn_count = 1; };
	void init_grid();
	void display_grid();
	bool is_col_available(unsigned col);
	bool set_token(char token, unsigned col);
	void check_for_4(char token1, char token2);
	unsigned get_bot_move();
	bool is_game_over() { return this->game_over; }
	unsigned get_turn_count() { return this->turn_count; }
};
