#include "functions.h"
#include <curses.h>
#include <signal.h>

char msg[][100] = {"Another Idiot (Alvaro Esperanca)","An Idiot (Johnathon Schroeder)","A Troll (Trevor Farkas)","","Developed by:","", "HOLE IN THE WALL"};

int c_done = 0;
int c_row;
int c_col;

void credits(){
  void roll_credits(int);

  c_row = LINES;
  c_col = COLS / 3;

  signal(SIGALRM, roll_credits);
  set_ticker(1000);

  clear();

  while(!c_done)
    continue;

  signal(SIGALRM, SIG_IGN);

}

void roll_credits(int signum){
  signal(SIGALRM, roll_credits);
  clear();

  c_row--;
  move(c_row+0, c_col);
  addstr(msg[0]);
  move(c_row+1, c_col);
  addstr(msg[1]);
  move(c_row+2, c_col);
  addstr(msg[2]);
  move(c_row+3, c_col);
  addstr(msg[3]);
  move(c_row+4, c_col);
  addstr(msg[4]);
  move(c_row+5, c_col);
  addstr(msg[5]);
  move(c_row+6, c_col);
  addstr(msg[6]);

  refresh();

  if(c_row <= 0)
    c_done = 1;
}
