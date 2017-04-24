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
	if(menu_option == 'S' || 's'){
		single_player_mode();
		keepgoing =0;
	}
	else if(menu_option == 'C' || 'c'){
	
		keepgoing = 0;
	}
	else if(menu_option == 'D' || 'd'){
		
	
		keepgoing = 0;
	}
	else if(menu_option == 'U' || 'u'){
	
		keepgoing = 0;
	}
	}
	
	
	
	
	endwin();
}
