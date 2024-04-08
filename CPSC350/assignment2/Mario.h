#ifndef MARIO_H
#define MARIO_H
#include "World.h"
#include <iostream>
using namespace std;

class World;
// class Level;
class Mario {
public: // intlizating all the public funcations and what type they aee and what
        // they are taking in
  Mario(int n);
  ~Mario();  // descrutior
  int lives; // instances
  int level;
  int power;
  int locx;
  int locy;
  int direction;
  void newGame(int l, int numLevel, int n, double c, double x, double g,
               double k, double m); // intlizating  the public funcations and
                                    // what type it is what it is taking in

private:
  World *MarioWorld; // creating a pointer to MarioWorld
};
#endif
