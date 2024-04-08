#include "GenQueue.h"

//defualt constructor
GenQueue::GenQueue(){
    mSize = 64; //default size of 64
    front = 0;
    rear = 0;
    numElements = 0;
    myQueue = new char[mSize];
}
//overloaded constructor
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
    // check if full
    if(isFull()){
        throw runtime_error("queue full");
    }
    myQueue[rear++] = d;
    rear%=mSize; //rear= rear% size ----> making a circular queue
    numElements++;
}
void GenQueue::enqueue(char d){
    // check if full
    if(isFull()){
        throw runtime_error("priority queue full");
    }
    int i=numElements-1;
    while(i>=0 && d<myQueue[i]){
        myQueue[i+1]=myQueue[i];
        i--;
    }
    myQueue[i+1] = d;
    //rear%=mSize; //rear= rear% size ----> making a circular queue
    numElements++;
}

char GenQueue::remove(){
    // check if empty
    if(isEmpty()){
        throw runtime_error("queue emptry");
    }
    char c = '\0'; //null character 
    c = myQueue[front++];
    front%=mSize; //making circular queue
    numElements--;
    return c;
}

char GenQueue::peek(){
    // check if empty
    if(isEmpty()){
        throw runtime_error("queue emptry");
    }
    return myQueue[front];
}

bool GenQueue::isFull(){
    return(numElements == mSize);
}

bool GenQueue::isEmpty(){
    return(numElements==0);
}

unsigned int GenQueue::getSize(){
    return numElements;
}

void GenQueue::printArray(){
    cout<<"Q size: "<< getSize()<<endl;
    cout<<"Front: "<<front<<endl;
    cout<<"rear: "<<rear<<endl;

    for (int i=0; i<mSize; ++i){
        cout<<"Q["<<i<<"]:"<<myQueue[i];
        if(i!= mSize-1){
            cout<<" | ";
        }
        
    }
    cout<<endl;
}