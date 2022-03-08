// connect4 = 7wx6h grid
// \u26AA	⚪	e2 9a aa	MEDIUM WHITE CIRCLE	
// \u26AB	⚫	e2 9a ab	MEDIUM BLACK CIRCLE
// \u1F534	🔴	f0 9f 94 b4	LARGE RED CIRCLE

const unsigned COLS = 7;
const unsigned ROWS = 6;
const char empty_token = '⚪';
const char player_token = '⚫';
const char bot_token = '🔴';

class Connect4 {
private:
	char display[ROWS][COLS] = {empty_token};
	unsigned turn_count = 0;
    bool game_over = false;
public:
	Connect4() {};
	void display_grid();
	bool is_col_available(unsigned col);
	void set_token(char token, unsigned col);
	void check_for_4(char token1, char token2);
    unsigned get_bot_move();
    bool is_game_over() { return this->game_over; }
    unsigned get_turn_count() { return this->turn_count; }
};
