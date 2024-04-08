#ifndef WORLD_H
#define WORLD_H
#include "Level.h"
#include <exception>
#include <string>

class Level; // forward declaration
class World{
    private: 
        Level* newLevel; // creating pointer to the new level 


    public:
        World(); //constructor
        ~World(); // descrtuctor

        bool D = false; // inlilziing the bool to be false 
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

// initliizing the public funcations and what type they are and what they are taking in 
void newWorld(int l, int numLevel, int n, double c, double x, double g, double k, double m, int locx, int locy);

bool isGoomba(int Gx, int Gy); // bool function to check if mario beats the Goomba
bool isKoopa(int Kx, int Ky); // bool function to check if mario beats the Koopa
bool isBoss(int bx, int by); // bool function to check if mario beats the Boss


int nextX(int x, int n); // int function to check the next x position
int nextY(int y, int n); // int function to check the next y position

string direction(int x, int y, int xx, int yy); // string function to check the direction



};
#endif