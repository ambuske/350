#ifndef MONOSTACK_H
#define MONOSTACK_H

#include<iostream>
#include <exception>
using namespace std;

class MonoStack{

    public:
        MonoStack(); //default constructor
        MonoStack(int initialSize, char o); //overloaded constructor
        ~MonoStack(); //destructor

        //core functions
        void push(double data);
        double pop();// return and remove
        double peek(); //aka top, just returns DOES NOT remove

        //aux/helper functions
        bool isEmpty();
        bool isFull();
        int getSize();
        int stacksize;
        void printStack();

    private:
        int top;
        int mSize;
        double *myArray;
        char order;
};
#endif