#include "MonoStack.h"

int main(int argc ,char **argv){

    MonoStack *myStack = new MonoStack(8, 'i');
    try{
        myStack->push(5.0);
        myStack->push(7.0);
        myStack->push(9.0);
        myStack->printStack();

        myStack->push(6.0);
        myStack->printStack();
        //myStack->push(2.8);
        //myStack->push(5.2);

        // cout << "SIZE: " << myStack->getSize() << endl;
        // cout << "PEEK: " << myStack->peek() << endl;
        //cout << "POP: " << myStack->pop() << endl;
        //cout << "PEEK: " << myStack->peek() << endl;
        //cout << "SIZE: " << myStack->getSize() << endl;

        // while(!myStack->isEmpty()){
        //      cout << "POP: " << myStack->pop() << endl;
        // }
        // cout << "SIZE: " << myStack->getSize() << endl;
        // cout << "PEEK: " << myStack->peek() << endl;
    }
    catch(runtime_error &excpt){
        cout << excpt.what() << endl;
    }
    delete myStack;
    return 0;
}