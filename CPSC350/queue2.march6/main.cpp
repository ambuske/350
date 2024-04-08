#include "GenStack.h"

int main(int argc, char **argv){
    GenStack *myStack = new GenStack(5);  //stack is on the heap
    try{
        myStack->push(4);
        myStack->push(2);
        myStack->push(645);
        myStack->push(8);
        myStack->push(54);
        myStack->push(101);
        

        cout <<"SIZE: "<<myStack->getSize()<<endl;
        cout <<"PEEK: "<<myStack->peek()<<endl;
        cout <<"POP: "<<myStack->pop()<<endl;
        cout <<"SIZE: "<<myStack->getSize()<<endl;

        while(!myStack->isEmpty()){
            cout<<"POP: "<<myStack->pop()<<endl;
        }
        cout <<"SIZE: "<<myStack->getSize()<<endl;
        //cout <<"POP: "<<myStack->pop()<<endl;
    }
    catch(runtime_error &excpt){
        cout<<excpt.what()<<endl;
    }
    delete myStack;
    return 0;
}