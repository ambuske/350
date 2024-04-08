#include "MonoStack.h"

MonoStack::MonoStack(){
    mSize = 64; //default size of our stack
    top = -1;
    myArray = new double[mSize];

}

MonoStack::MonoStack(int initialSize, char o){
    mSize = initialSize;
    top = -1;
    myArray = new double[mSize];
    order = o;

}

MonoStack::~MonoStack(){
    cout << "stack destroyed, garbage taken out has been" << endl;
    delete[] myArray;
}



void MonoStack::push(double data){

    //check if stack is full
    if(isFull()){
        cout << " resizing stack is" << endl;
        double *temp = new double[2*mSize];
        for(int i = 0; i < mSize; ++i){
            temp[i] = myArray[i]; //copy data from old array into new larger array
        }
        mSize *= 2; //shorthand for mSize = mSize * 2
        delete[] myArray;
        myArray = temp;
    }
    if(order=='i'){
        while (!isEmpty() && ((data < myArray[top]) )) {
            pop(); // Pop elements until monotonicity is maintained
        }

    }else if(order=='d'){
        while (!isEmpty() && ((data > myArray[top]) )) {
            pop(); // Pop elements until monotonicity is maintained

        }

    }

    

    myArray[++top] = data;
}


double MonoStack::pop(){
    //check if stack is empty
    if(isEmpty()){
        throw runtime_error("stack is empty, nothing to pop");
    }
    return myArray[top--];
    
}

double MonoStack::peek(){
    //check if stack is empty
    if(isEmpty()){
        throw runtime_error("stack is empty, nothing to peek");
    }
    return myArray[top];
}

bool MonoStack::isEmpty(){
    return (top == -1);
}

bool MonoStack::isFull(){
    return (top == mSize-1);
}

int MonoStack::getSize(){
    return top + 1;
}

void MonoStack::printStack(){
    for (int i = 0; i <= top; i++){
        cout << myArray[i] << " ";
    }
    cout << endl;
}