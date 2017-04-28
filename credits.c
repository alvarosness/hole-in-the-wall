#include "functions.h"
#include <curses.h>
#include <signal.h>

char msg[][100] = {"Another Idiot (Alvaro Esperanca)","","An Idiot (Johnathon Schroeder)","","A Troll (Trevor Farkas)","","Developed by:","", "HOLE IN THE WALL"};

int c_done = 0;
int c_row;
int c_col;

void credits(){
  void roll_credits(int);

  c_row = LINES;
  c_col = COLS / 3;

  signal(SIGALRM, roll_credits);
  set_ticker(500);

  clear();

  while(!c_done)
    continue;

  signal(SIGALRM, SIG_IGN);

}

void roll_credits(int signum){
  signal(SIGALRM, roll_credits);
  clear();

  c_row--;
  move(c_row, c_col);
  addstr(msg[0]);

  c_row--;
  move(c_row, c_col);
  addstr(msg[1]);

  c_row--;
  move(c_row, c_col);
  addstr(msg[2]);
  
  c_row--;
  move(c_row, c_col);
  addstr(msg[3]);
  
  c_row--;
  move(c_row, c_col);
  addstr(msg[4]);
  
  c_row--;
  move(c_row, c_col);
  addstr(msg[5]);
  
  c_row--;
  move(c_row, c_col);
  addstr(msg[6]);
  
  c_row--;
  move(c_row, c_col);
  addstr(msg[7]);
  
  c_row--;
  move(c_row, c_col);
  addstr(msg[8]);

  refresh();

  if(c_row <= 0)
    c_done = 1;
}
