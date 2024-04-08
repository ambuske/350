#include "Mario.h"

Mario::Mario(int n) { //default constructor takes in int n which is the dimension of the array

}
Mario::~Mario(){ //destructor

}

void Mario::newGame(int l, int numLevel, int n, double c, double x, double g, double k, double m){ //new game takes in all the variables
    int locx = rand()%n; //a random start locaion for mario
    int locy = rand()%n;
    MarioWorld = new World[1]; //creating 1 world
    MarioWorld[1].newWorld(l, numLevel, n, c, x, g, k, m, locx, locy); //populating the world with the variables

}
