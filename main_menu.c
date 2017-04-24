#include <curses.h>

int main_menu(){
	clear();
	
	int row = LINES / 3;
	int col = COLS / 3;
	
	move(row, col);
	addstr("Hole in the Wall");
		
	move(row+1, col);
	addstr("(S)ingle Player Mode");

	move(row+2, col);
	addstr("(C)o-op Mode");

	move(row+3, col);
	addstr("(D)eathmatch");

	move(row+4, col);
	addstr("(C)redits");

	move(LINES-1,0);

	return getch();
}
