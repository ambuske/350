#ifndef WORLD_H
#define WORLD_H
#include "Level.h"
#include <exception>
#include <string>

class Level;
class World{
    private: 
        Level* newLevel;


    public:
        World();
        ~World();

        bool D = false;
        int power;

      int lives;
      string PL0 = "PL0";
        string PL1 = "PL1";
        string PL2 = "PL2";
        int L;
    int i;
    int k;
        int j;
    int numLevel;
    int myCoin = 0;
    int defeatedEnemy;
void newWorld(int l, int numLevel, int n, double c, double x, double g, double k, double m, int locx, int locy);

bool isGoomba(int Gx, int Gy);
bool isKoopa(int Kx, int Ky);
bool isBoss(int bx, int by);


int nextX(int x, int n);
int nextY(int y, int n);



};
#endif