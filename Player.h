#ifndef _PLAYER_
#define _PLAYER_

struct Player{
  int x_;
  int y_;
  int HP_;
  char sprite_;
};

typedef struct Player Player;

void init_Player(Player *p){
  p->x_ = 0;
  p->y_ = 0;
  p->HP_ = 3;
  p->sprite_ = '>';
}

#endif
