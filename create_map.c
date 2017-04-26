//create_map.c
#include "functions.h"
#include <curses.h>
#include <stdlib.h>
#include <string.h>

void create_map(char map[][2000]){
  int col;
  int row, count;
  int start_x, start_y;
  char entry[] = "Press Any Key to Begin";
  start_x = COLS / 2 - 11;
  start_y = LINES / 2;

	for(col = 0; col < 2000; col++)
		for(row = 0; row < LINES; row++)
			map[row][col] = ' ';
			
  for(col = 0; col < 22; col++)
     map[start_y][start_x + col] = *(entry + col);

  for(col = 0; col < 2000; col++)
  {
    if(col < COLS){
    	;
    }
    
    else if(col < 100){
      if (col % 10 == 0 )
      {
        for( row = 2; row < LINES; row++)
          map[row][col] = '|';
        for(count = 0; count < 5; count++)
          map[rand()%LINES][col] = ' ';
      }
    }
    else if(col <200){
      if (col % 10 == 0 )
        {
          for( row = 2; row < LINES; row++)
            map[row][col] = '|';
          for(count = 0; count < 4; count++)
            map[rand()%LINES][col] = ' ';
        }
    }
    else if(col <300){
      if (col % 8 == 0 )
        {
          for( row = 2; row < LINES; row++)
            map[row][col] = '|';
          for(count = 0; count < 4; count++)
            map[rand()%LINES][col] = ' ';
        }
    }
    else if(col <400){
      if (col % 8 == 0 )
        {
          for( row = 2; row < LINES; row++)
            map[row][col] = '|';
          for(count = 0; count < 3; count++)
            map[rand()%LINES][col] = ' ';
        }
    }
    else if(col <600){
      if (col % 6 == 0 )
        {
          for( row = 2; row < LINES; row++)
            map[row][col] = '|';
          for(count = 0; count < 4; count++)
            map[rand()%LINES][col] = ' ';
        }
    }
    else if(col <1000){
      if (col % 5 == 0 )
        {
          for( row = 2; row < LINES; row++)
            map[row][col] = '|';
          for(count = 0; count < 2; count++)
            map[rand()%LINES][col] = ' ';
        }
    }
		
  }

}
