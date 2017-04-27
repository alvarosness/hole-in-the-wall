#include <curses.h>
#include "functions.h"

int main(int argc, char** argv){
	char menu_option;
	int keepgoing = 1;

	initscr();
	crmode();
	noecho();
	curs_set(FALSE);
	while (keepgoing == 1){
		menu_option = main_menu();
		if(menu_option == 'S' || menu_option == 's'){
			single_player_mode();
			keepgoing =0;
		}
		else if(menu_option == 'C' || menu_option == 'c'){
			keepgoing = 0;
		}
		else if(menu_option == 'D' || menu_option == 'd'){
			keepgoing = 0;
		}
		else if(menu_option == 'A' || menu_option == 'A'){
			keepgoing = 0;
		}
	}
	
	endwin();
}
