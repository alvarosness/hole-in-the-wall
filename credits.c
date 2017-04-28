#include "functions.h"
#include <curses.h>
#include <signal.h>

char msg[][100] = {"HOLE IN THE WALL",
                    "",
                    "Developed by:",
                    "",
                    "A Troll (Trevor Farkas)",
                    "An Idiot (Johnathon Schroeder)",
                    "Another Idiot (Alvaro Esperanca)",
                    "",
                    "Thanks Shia LeBeouf"
};

int c_done = 0;
int c_row;
int c_col;

void credits(){
  void roll_credits(int);

  c_row = LINES;
  c_col = COLS / 3;

  signal(SIGALRM, roll_credits); //set signal handler and timer for alarm signal
  set_ticker(1000);

  clear();

  while(!c_done)  //check done flag
    continue;

  signal(SIGALRM, SIG_IGN); //ignore alarm signal once done

}

void roll_credits(int signum){
  signal(SIGALRM, roll_credits);  
  clear();

  c_row--;      //move text
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
  move(c_row+7, c_col);
  addstr(msg[7]);
  move(c_row+8, c_col);
  addstr(msg[8]);
  
  refresh();

  if(c_row <= 0) //if at the top trigger done flag
    c_done = 1;
}
