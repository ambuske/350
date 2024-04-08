#include "GenStack.h"

void reverseStack(GenStack *ogStack);
int main(int argc, char **argv){
    GenStack *myStack = new GenStack(5);  //stack is on the heap

    try{
        myStack->push('f');
        myStack->push('o');
        myStack->push('o');
        myStack->push('b');
        myStack->push('a');
        myStack->push('r');
        
        
        reverseStack(myStack);
        
        
        myStack->push('f');
        myStack->push('o');
        myStack->push('o');
        myStack->push('b');
        myStack->push('a');
        myStack->push('r');
        //myStack->reverseStack();
        

        cout <<"SIZE: "<<myStack->getSize()<<endl;
        cout <<"PEEK: "<<myStack->peek()<<endl;
        cout <<"POP: "<<myStack->pop()<<endl;
        cout <<"SIZE: "<<myStack->getSize()<<endl;

        while(!myStack->isEmpty()){
            cout<<"POP: "<<myStack->pop()<<endl;
        }
        cout <<"SIZE: "<<myStack->getSize()<<endl;
        cout <<"POP: "<<myStack->pop()<<endl;
    }
    catch(runtime_error &excpt){
        cout<<excpt.what()<<endl;
    }
    delete myStack;
    return 0;
}

void reverseStack(GenStack *ogStack) {
// Create a temporary stack to store reversed elements
    GenStack tempStack;

// Transfer elements from original stack to temporary stack
    while (!ogStack->isEmpty()) {
        tempStack.push(ogStack->pop());
    }

// Create another temporary stack to store the reversed order
    GenStack reversedTempStack;

// Transfer elements from temporary stack to another temporary stack
    while (!tempStack.isEmpty()) {
        reversedTempStack.push(tempStack.pop());
    }

// Transfer elements back from the reversed temporary stack to the original stack
    while (!reversedTempStack.isEmpty()) {
        ogStack->push(reversedTempStack.pop());
    }
}