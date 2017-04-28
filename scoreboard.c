#include "functions.h"
#include <curses.h>

void scoreboard(){
  clear();
  int row = LINES/2;
  int col = COLS/2;
  
  mvaddstr(row, col, "TOP SCORES");
  mvaddstr(row+1, col, "1.1738");
  mvaddstr(row+2, col, "2.420");
  mvaddstr(row+3, col, "3.69");
  mvaddstr(row+4, col, "4.42");
  mvaddstr(row+5, col, "5.0");
  refresh();
  
  getch();
  
}
