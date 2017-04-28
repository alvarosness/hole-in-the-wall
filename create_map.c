//create_map.c
#include "functions.h"
#include <curses.h>
#include <stdlib.h>
#include <string.h>

#define WALL_SPRITE 178

//recieves map created in singleplayer.c
void create_map(char map[][2000]){
  int col;
  int row, count;
  int start_x, start_y;
  char entry[] = "Press Any Key to Begin";
 
 //finds start position for begin message
  start_x = COLS / 2 - 11;
  start_y = LINES / 2;

//fills map with blank spaces
  for(col = 0; col < 2000; col++)
    for(row = 0; row < LINES; row++)
      map[row][col] = ' ';

//creates map one column at a time
  for(col = 0; col < 2000; col++){
    if(col < 10){
    	;
    }

//each if shows the next difficulty for the levels
    else if(col < 100){//how many tics till next change
      if (col % 10 == 0 )//blank spaces between walls
      {
        for( row = 3; row < LINES; row++)//builds the wall
          map[row][col] = WALL_SPRITE;
        for(count = 0; count < 5; count++)//puts holes in the wall
          map[rand()%LINES][col] = ' ';
      }
    }
    else if(col <200){
      if (col % 10 == 0 )
        {
          for( row = 3; row < LINES; row++)
            map[row][col] = WALL_SPRITE;
          for(count = 0; count < 3; count++)
            map[rand()%LINES][col] = ' ';
        }
    }
    else if(col <300){
      if (col % 8 == 0 )
        {
          for( row = 3; row < LINES; row++)
            map[row][col] = WALL_SPRITE;
          for(count = 0; count < 3; count++)
            map[rand()%LINES][col] = ' ';
        }
    }
    else if(col <400){
      if (col % 8 == 0 )
        {
          for( row = 3; row < LINES; row++)
            map[row][col] = WALL_SPRITE;
          for(count = 0; count < 3; count++)
            map[rand()%LINES][col] = ' ';
        }
    }
    else if(col <600){
      if (col % 7 == 0 )
        {
          for( row = 3; row < LINES; row++)
            map[row][col] = WALL_SPRITE;
          for(count = 0; count < 3; count++)
            map[rand()%LINES][col] = ' ';
        }
    }
    else if(col <1000){
      if (col % 6 == 0 )
        {
          for( row = 3; row < LINES; row++)
            map[row][col] = WALL_SPRITE;
          for(count = 0; count < 2; count++)
            map[rand()%LINES][col] = ' ';
        }
    }

  }

}
