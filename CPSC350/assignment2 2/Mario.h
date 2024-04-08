#ifndef MARIO_H
#define MARIO_H
#include <iostream>
#include "World.h"
using namespace std;


class World;
//class Level;
class Mario{
    public:
        Mario(int n);
        ~Mario();
        int lives;
        int level;
        int power;
        int locx;
        int locy;
        int direction;
        void newGame(int l, int numLevel, int n, double c, double x, double g, double k, double m);


    private:
        World* MarioWorld;


};
#endif
