#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <cstdlib>
using namespace std;



class Level {

private: 
  int n;
  char** myArray; // pointers to the array 


public:
  Level(); // constructor
  Level(int n); // defult 
  ~Level(); // destrctuor 
// initliizing the publuc funcations and what type they are and what they are taking in 
    void populate(double c, double x, double g, double k, double m);   
    void populateLastLevel(double c, double x, double g, double k, double m);
    char access(int x, int y);
    void removeTile(int x, int y);
    void printArray(int n);
    void MarioPos(int x, int y);
    void printMario(int n, int x, int y);




};
#endif

