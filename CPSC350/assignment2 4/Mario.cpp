#include "Mario.h"

Mario::Mario(int n) {
    int locx = rand()%n;
    int locy = rand()%n;
    
    

}
Mario::~Mario(){
    //delete[] MarioWorld;
}

void Mario::newGame(int l, int numLevel, int n, double c, double x, double g, double k, double m){
    int locx = rand()%n;
    int locy = rand()%n;
    MarioWorld = new World[1];
    MarioWorld[1].newWorld(l, numLevel, n, c, x, g, k, m, locx, locy);
    
}
