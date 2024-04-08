#ifndef GENQUEUE_H
#define GENQUEUE_H
#include <iostream>
#include <exception>

using namespace std;
//array based genqueue

class GenQueue{
    public:
        GenQueue(); //default constructor
        GenQueue(int maxSize); //overloaded constructor
        ~GenQueue(); //destructor

        //core functions
        void insert(char d); //aka enqueue() method
        char remove(); //dequque() method 
        void enqueue(char d); //priority queue insert

        //aux/helper functrions
        char peek(); //who is at the front of the  queue
        bool isFull();
        bool isEmpty();
        unsigned int getSize(); //cannot be less than zero
        void printArray(); //helper function to visualize arraybased queue 
    private:
        int mSize;
        int front;
        int rear;
        unsigned int numElements;
        char *myQueue;

};

#endif