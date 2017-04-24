#include "functions.h"
#include <curses.h>

void move(int * x, int * y){
  num = rand() % 8;
  if (num == 0)
    y--;
  
  else if(num == 1)
    y++;
    
  x--;
}

void single_player_mode(){
  clear();
  char move;
  int x;
  int y;
  x=0;
  y=0;
   mvaddch(y,x,'>');
   refresh();
  while(1){
    move = getch();
    if (move == 'w'){
      clear();
      y--;
      if(y<0)
        y=0;
      mvaddch(y,x,'>');
      refresh();
    }
    else if(move == 's'){
      clear();
      y++;
      if(y>LINES-1)
        y= LINES-1;
      mvaddch(y,x,'>');
      refresh();
    }
    else if(move =='a'){
      clear();
      x--;
      if(x<0)
        x=0;
      mvaddch(y,x,'>');
      refresh();
    }
    else if(move == 'd'){
      clear();
      x++;
      if(x>COLS-1)
        x= COLS-1;
      mvaddch(y,x,'>');
      refresh();
    }
  }
}
