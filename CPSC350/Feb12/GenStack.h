#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>
#include <exception>
using namespace std;

class GenStack{
    public:
        GenStack(); //default constructor
        GenStack(int maxSize); //overloaded constructor
        ~GenStack(); //destructor 

        //core functions
        void push(char data);
        char pop();
        char peek(); //aka top

        //aux functions
        bool isEmpty();
        bool isFull();
        int getSize();
        //void reverseStack();

    private:
        int top; //keep track of top of stack
        int mSize;
        char *myArray; //use pointer so you can use consturctor and can change size whenever
        char *newArray;
};

#endif