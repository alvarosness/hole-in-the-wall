#include "functions.h"
#include <curses.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>

int mvflag;

void move_something(int * x, int * y){
  int num = rand() % 8;
  if (num == 0)
    y--;

  else if(num == 1)
    y++;

  x--;
}

void single_player_mode(){

  // char separator[COLS];
  int i;
  //
  // for(i = 0; i < COLS-1; i++)
  //   separator[i] = '-';
  // separator[i] = '\0';

  cbreak();
  nodelay(stdscr, TRUE);
  scrollok(stdscr, TRUE);
  void on_alarm(int);
  mvflag = 0;
  clear();
  char move;
  char map[LINES][2000];
  int x, map_x;
  int y, map_y;
  int delay = 250;
  int count = 0;
  create_map(map);
  x=0;
  y=0;
  signal(SIGALRM, on_alarm);
  set_ticker(delay);
   mvaddch(y,x,'>');
   refresh();

  while(1){
    move = getch();
   if (move == 'w'){
      clear();
      y--;
      if(y<3)
        y=3;
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

    for(map_x = 0; map_x < COLS; map_x++){
      for(map_y = 0; map_y < LINES; map_y++){
        mvaddch(map_y,map_x, map[map_y][map_x+count]);
      }
    }

    for(i = 0; i < COLS; i++)
      mvaddch(1, i, '_');

    mvaddch(y,x,'>');

   if(mvflag == 1){
     count++;
     mvflag = 0;
   }
   refresh();

   // Collision Detection
  if(map[y+1][x + count] == 178){
    clear();
    refresh();
    break;
  }

  }
}


void on_alarm(int signum){
  signal(SIGALRM, on_alarm);
  mvflag = 1;
}
