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
		if(menu_option == 'P' || menu_option == 'p'){
			single_player_mode();
		}
		else if(menu_option == 'S' || menu_option == 's'){

		}
		else if(menu_option == 'C' || menu_option == 'c'){
			credits();
		}
		else if(menu_option == 'Q' || menu_option == 'q'){
			keepgoing = 0;
		}
	}

	endwin();
}
