#include "GenQueue.h"

GenQueue::GenQueue(){
    mSize = 64; //default size of our queue
    front = 0;
    rear = 0;
    numElements = 0;
    myQueue = new char[mSize];
}

GenQueue::GenQueue(int maxSize){
    mSize = maxSize;
    front = 0;
    rear = 0;
    numElements = 0;
    myQueue = new char[mSize];
}

GenQueue::~GenQueue(){
    delete[] myQueue;
}

void GenQueue::insert(char d){
    //check if full
    if(isFull()){
        throw runtime_error("queue is full");
    }

    myQueue[rear++] = d;
    rear %= mSize; //rear = rear % mSize;
    numElements++;
}

void GenQueue::enqueue(char d){
    if(isFull()){
        throw runtime_error("priority queue is full");
    }

    int i = numElements-1;
    while(i >= 0 && d < myQueue[i]){
        myQueue[i+1] = myQueue[i];
        i--;
    }
    myQueue[i+1] = d;
    numElements++;
}

char GenQueue::remove(){
    //check if empty
    if(isEmpty()){
        throw runtime_error("queue is empty, nothing to remove");
    }
    char c = '\0';
    c = myQueue[front++];
    front %= mSize;
    numElements--;
    return c;
}

char GenQueue::peek(){
    if(isEmpty()){
        throw runtime_error("queue is empty, nothing to remove");
    }
    return myQueue[front];
}

bool GenQueue::isFull(){
    return (numElements == mSize);
}

bool GenQueue::isEmpty(){
    return (numElements == 0);
}

unsigned int GenQueue::getSize(){
    return numElements;
}

void GenQueue::printArray(){
  cout << "Q SIZE: " << getSize() << endl;
  cout << "FRONT: " << front << endl;
  cout << "REAR: " << rear << endl;

  for(int i = 0; i < mSize; ++i){
     cout << "Q["<< i << "]: " << myQueue[i];
     if(i != mSize-1){
       cout << " | ";
     }
  }
  cout << endl;
}