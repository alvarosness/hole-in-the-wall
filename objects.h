#ifndef _OBJECTS_
#define _OBJECTS_

/**
 * Spaceship is the object that will fly through space
 *
 * x_coord and y_coord are the position of the Spaceship in space.
 * x_speed and y_speed is how fast the Spaceship moves in the x and y directions
 * 	after user input is received.
 * HP are the health points the ship has.
 */
struct Spaceship{
	int x_coord, y_coord;
	int x_speed, y_speed;
	int HP;
	char* sprite;
};

struct Bullet{
	int x_coord, y_coord;
	int x_acc;
	int power;
	char sprite;
};

typedef struct Spaceship Spaceship;
typedef struct Bullet Bullet;

struct Player{
	Spaceship ship;
	int score;	
};

typedef struct Player Player;

#endif
