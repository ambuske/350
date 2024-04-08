#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include <exception>

using namespace std;
//Array based Queue
class GenQueue{
    public:
        GenQueue(); //default constructor
        GenQueue(int maxSize); //overloaded constructor
        ~GenQueue(); //destructor

        //core functions
        void insert(char d); //enqueue()
        char remove();//dequeue
        void enqueue(char d); //priority queue insert

        //aux functions
        char peek();
        bool isFull();
        bool isEmpty();
        unsigned int getSize();
        void printArray();//helper function to help visualize our array based queue

    private:
        unsigned int mSize;
        unsigned int front;
        unsigned int rear;
        unsigned int numElements;
        char *myQueue;
};

#endif