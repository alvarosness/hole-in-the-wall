//create_map.c
#include "functions.h"
#include <curses.h>
#include <stdlib.h>
#include <string.h>

#define WALL_SPRITE 178

void create_map(char map[][2000]){
  int col;
  int row, count;
  int start_x, start_y;
  char entry[] = "Press Any Key to Begin";
  start_x = COLS / 2 - 11;
  start_y = LINES / 2;

  // Setting the initial values of the map to blank space
  for(col = 0; col < 2000; col++)
     for(row = 0; row < LINES; row++)
 	map[row][col] = ' ';


  for(col = 0; col < 2000; col++)
  {
    // First Portion of the map. Has no Walls
    if(col < COLS){
    	;
    }
    // Creating walls with a spacing of 10
    else if(col < 100){
      if (col % 10 == 0 )
      {
        for( row = 3; row < LINES; row++) //Building walls
          map[row][col] = WALL_SPRITE;
        for(count = 0; count < 5; count++) //Making spaces
          map[rand()%LINES][col] = ' ';
      }
    }
    // Creating walls with a spacing of 10
    else if(col <200){
      if (col % 10 == 0 )
        {
          for( row = 3; row < LINES; row++) //Building walls
            map[row][col] = WALL_SPRITE;
          for(count = 0; count < 4; count++) //Making spaces
            map[rand()%LINES][col] = ' ';
        }
    }
    // Creating walls with a spacing of 8
    else if(col <300){
      if (col % 8 == 0 )
        {
          for( row = 3; row < LINES; row++) //Building walls
            map[row][col] = WALL_SPRITE;
          for(count = 0; count < 4; count++) //Making spaces
            map[rand()%LINES][col] = ' ';
        }
    }
    // Creating walls with a spacing of 8
    else if(col <400){
      if (col % 8 == 0 )
        {
          for( row = 3; row < LINES; row++) //Building walls
            map[row][col] = WALL_SPRITE;
          for(count = 0; count < 3; count++) //Making spaces
            map[rand()%LINES][col] = ' ';
        }
    }
    // Creating walls with spacing of 6
    else if(col <600){
      if (col % 6 == 0 )
        {
          for( row = 3; row < LINES; row++) //Building walls
            map[row][col] = WALL_SPRITE;
          for(count = 0; count < 4; count++) //Making spaces
            map[rand()%LINES][col] = ' ';
        }
    }
    // Creating walls with spacing of 5
    else if(col <1000){
      if (col % 5 == 0 )
        {
          for( row = 3; row < LINES; row++) //Building walls
            map[row][col] = WALL_SPRITE;
          for(count = 0; count < 2; count++) //Making spaces
            map[rand()%LINES][col] = ' ';
        }
    }

  }

}
