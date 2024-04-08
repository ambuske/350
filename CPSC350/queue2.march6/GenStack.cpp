#include "GenStack.h"

GenStack::GenStack(){

    myArray = new int[mSize];
}

GenStack::~GenStack(){
    cout<<"stack deleted"<<endl;
    delete[] myArray;
}

void GenStack::push(int data){
    // check if stack is full
    if(isFull()){
        //throw runtime_error("stack is full");
        cout<< "stack is resizing" <<endl;
        int *temp = new int[2*mSize];   //creating a new array
        for(int i=0; i< mSize; ++i){
            temp[i] = myArray[i];     //copy data over to new array
        }
        mSize *=2; //double size of array
        delete[] myArray;
        myArray=temp;
    }
    //top++; --> on seperate line or combine like below
    myArray[++top] = data; //add to array
}

int GenStack::pop(){
    //check if empty
    if(isEmpty()){
        throw runtime_error("stack is empty, nothing to remove");
    }
    return myArray[top--]; 
}

int GenStack::peek(){
    if(isEmpty()){
        throw runtime_error("stack is empty, nothing to remove");
    }
    return myArray[top]; //checking what is there 
}

bool GenStack::isFull(){
    
}

bool GenStack::isEmpty(){
    return(top==-1);
}

int GenStack::getSize(){
    return top+1;
}