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
  char map[ROWS][2000];
  int x, map_x;
  int y, map_y;
  int delay = 200;
  create_map(map);
  x=0;
  y=0;
  signal(SIGALRM, alarm);
  set_ticker(delay);
  
   mvaddch(y,x,'>');
   refresh();
  while(1){
    move = getch();
    if (move == 'w'){
      clear();
      y--;
      if(y<0)
        y=0;
    }
    else if(move == 's'){
      clear();
      y++;
      if(y>LINES-1)
        y= LINES-1;
    }
    else if(move =='a'){
      clear();
      x--;
      if(x<0)
        x=0;
    }
    else if(move == 'd'){
      clear();
      x++;
      if(x>COLS-1)
        x= COLS-1;
    }
    
      mvaddch(y,x,'>');
    
    for(map_x = 0; map_x < COLS; map_x++)
      for(map_y = 0; map_y < ROWS; map_y++)
        mvaddch(y,x,map[map_x][map_y]);
    refresh()
    

  }
}
void alarm (int signum){
  
  
  
  
}
