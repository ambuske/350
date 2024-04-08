#include "GenQueue.h"

int main(int argc, char **argv){
    GenQueue *myQueue = new GenQueue(5);
    try{
        myQueue->enqueue('f');
        myQueue->enqueue('o');
        myQueue->enqueue('o');
        myQueue->enqueue('b');
        myQueue->enqueue('a');
        // myQueue->insert('f');
        // myQueue->insert('o');
        // myQueue->insert('o');
        // myQueue->insert('b');
        // myQueue->insert('a');
        //myQueue->insert('X');
        cout<<"PEEK: "<<myQueue->peek()<<endl;
        cout<<"Remove: "<<myQueue->remove()<<endl;
        cout<<"PEEK: "<<myQueue->peek()<<endl;
        myQueue->printArray();

        while(!myQueue->isEmpty()){
            cout<<"REMOVE: "<<myQueue->remove()<<endl;
        }
        //cout <<"PEEK: "<<myQueue->peek()<< endl;
        myQueue->printArray();
    }catch(runtime_error &excpt){
        cerr<<excpt.what()<<endl;
    }
    delete myQueue;
    return 0;
}