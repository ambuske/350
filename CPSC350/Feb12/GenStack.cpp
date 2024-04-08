#include "GenStack.h"

GenStack::GenStack(){
    mSize = 64; //default size
    top = -1;
    myArray = new char[mSize];
}
GenStack::GenStack(int maxSize){
    mSize = maxSize; 
    top = -1;
    myArray = new char[mSize];
}
GenStack::~GenStack(){
    cout<<"stack deleted"<<endl;
    delete[] myArray;
}

void GenStack::push(char data){
    // check if stack is full
    if(isFull()){
        //throw runtime_error("stack is full");
        cout<< "stack is resizing" <<endl;
        char *temp = new char[2*mSize];   //creating a new array
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

char GenStack::pop(){
    //check if empty
    if(isEmpty()){
        throw runtime_error("stack is empty, nothing to remove");
    }
    return myArray[top--]; 
}

char GenStack::peek(){
    if(isEmpty()){
        throw runtime_error("stack is empty, nothing to remove");
    }
    return myArray[top]; //checking what is there 
}

bool GenStack::isFull(){
    return(top==mSize-1);
}

bool GenStack::isEmpty(){
    return(top==-1);
}

int GenStack::getSize(){
    return top+1;
}
/*
void GenStack::reverseStack(){
    newArray = new char[mSize];
    int n= getSize();
    for(int i =0; i<n; i++){
        newArray[i] = pop();
    }
    cout<<"new array: "<<endl;
    for(int i =0; i<n; i++){
        cout<<newArray[i]<<endl;
    }
    
}
*/