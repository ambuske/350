#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>
#include <exception>
using namespace std;

class GenStack{
    public:
        GenStack(); //default constructor
        
        ~GenStack(); //destructor 

        //core functions
        void push(int data);
        int pop();
        int peek(); //aka top

        //aux functions
        bool isEmpty();
        bool isFull();
        int getSize();

    private:
        int top; //keep track of top of stack
        int mSize;
        int *myArray; //use pointer so you can use consturctor and can change size whenever

};

#endif