#include "functions.h"
#include <curses.h>

void scoreboard(){
  clear();
  int row = LINES/3;
  int col = COLS/3;
  char topscore[10];
  
  if(read_score(topscore)){
    mvaddstr(row, col, "TOP SCORE");
    mvaddstr(row+1, col, topscore);
  }else{
    mvaddstr(row, col, "No Top Score Available");
  }
  refresh();
  
  getch();
  
}

int read_score(char * str){
  FILE * fd;
  
  fd = fopen("", "r");
  
  if(fd == NULL)
    return 0;
    
  fgets(str,8,fd);
  
  fclose(fd);
  
  return 1;
}
