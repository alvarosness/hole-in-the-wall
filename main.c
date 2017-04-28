#include <curses.h>
#include "functions.h"

int main(int argc, char** argv){
	char menu_option;
	int keepgoing = 1;

	initscr();	//setting up window
	crmode();	//setting attributes
	noecho();
	curs_set(FALSE);
	while (keepgoing == 1){		//directing the program to a function based off user input
		menu_option = main_menu();
		if(menu_option == 'P' || menu_option == 'p'){
			single_player_mode();
		}
		else if(menu_option == 'C' || menu_option == 'c'){
			credits();
		}
		else if(menu_option == 'Q' || menu_option == 'q'){
			keepgoing = 0;
		}
	}

	endwin(); //closing window
}
