#include <curses.h>

int main_menu(){
	clear();

	int row = LINES / 3;
	int col = COLS / 3;

	move(row, col);			//display title and user options
	addstr("Hole in the Wall");

	move(row+1, col);
	addstr("(P)lay");

	move(row+2, col);
	addstr("(C)redits");

	move(row+3, col);
	addstr("(Q)uit");

	move(LINES-1,0);

	return getch();
}
