#include "Setup.hpp"

// Post : The screen is initialized and ready for curses functions to be used.
void startup(void)
{
	initscr();
	curs_set(0);
	clear();
	noecho();
	cbreak();

	mvaddstr(0, 46, "blackjack");
	for(int i = 0; i < 80; ++i)  {
		mvaddch(1, i, '*');
		mvaddch(ROW, i, '*');
	}
	for(int i = 2; i < 40; ++i) {
		mvaddch(i, 0, '*');
		mvaddch(i , COL - 1, '*');
	}
}

// Pre  : startup(void) has been called.
// Post : The screen is terminated and curses functions can no longer be used.
void terminate(void)
{
	mvcur( 0, COLS - 1, LINES - 1, 0 );
	clear();
	refresh();
	endwin();
}