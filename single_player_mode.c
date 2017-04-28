#include "functions.h"
#include <curses.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>


int mvflag;

void single_player_mode(){

  int i;
  char score_str[4];
  int score = 0;
  int col;
  
  //turning off no delay
  cbreak();
  nodelay(stdscr, TRUE);
  //setting variables for ticker
  scrollok(stdscr, TRUE);
  void on_alarm(int);
  mvflag = 0;
  clear();
  char move;
  char entry[] = "Press space to begin";
  char map[LINES][2000];
  int x, map_x;
  int y, map_y;
  int delay = 250;
  int count = 0;
  
  //initiate random map
  create_map(map);
  
  //places welcome message
  for(col = 0; col < 20; col++)
     mvaddch(LINES / 2, COLS / 2 - 11 + col, *(entry + col));
  
  x=0;
  y=2;
  
  //starts timers
  signal(SIGALRM, on_alarm);
  set_ticker(delay);
   mvaddch(y,x,'>');
   refresh();

//waits for space to start
  while(getch() != ' ');

  while(1){
    //checks for player movement
    move = getch();
    
    //change location
   if (move == 'w'){
      clear();
      y--;
      if(y<2)
        y=2;
    }
    else if(move == 's'){
      clear();
      y++;
      if(y>LINES-2)
        y= LINES-2;
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
//puts the seeable area on the map
    for(map_x = 0; map_x < COLS; map_x++){
      for(map_y = 0; map_y < LINES; map_y++){
        mvaddch(map_y,map_x, map[map_y][map_x+count]);
      }
    }
//adds upper boundry
    for(i = 0; i < COLS; i++)
      mvaddch(1, i, '_');

//puts game title
    mvaddstr(0, COLS/2 - 10, "Hole In The Wall");

//displays score
    mvaddstr(0, COLS - 10, "Score: ");
    score_to_string(score_str, score);
    mvaddstr(0, COLS - 4, score_str);

//places your character
    mvaddch(y,x,'>');

//if set from ticker increments map
   if(mvflag == 1){
     count++;
     score++;
     mvflag = 0;
   }
   refresh();

   // Collision Detection
  if(map[y+1][x + count] != ' '){
    clear();
    refresh();
    break;
  }

  }

  // Ignore alarms once the game ends
  signal(SIGALRM, SIG_IGN);
  clear();
  move(LINES/3, COLS/3);
  addstr("Congrats your score is: ");
  addstr(score_str);
  refresh();
  sleep(2);

}

//converts integer score to string
void score_to_string(char * str, int score){
  int ones, tens, hundreds;

  ones = score % 10;
  score = score / 10;
  tens = score % 10;
  score = score / 10;
  hundreds = score % 10;

//adds values to string
  str[0] = 0x30 + hundreds;
  str[1] = 0x30 + tens;
  str[2] = 0x30 + ones;
  str[3] = '\0';
}

//alarm function
void on_alarm(int signum){
  signal(SIGALRM, on_alarm);
  mvflag = 1;
}
