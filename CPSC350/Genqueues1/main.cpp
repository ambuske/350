#include "GenQueue.h"

int main (int argc, char **argv){

    GenQueue *myQueue = new GenQueue(5);
    try{
        myQueue->enqueue('f');
        myQueue->enqueue('o');
        myQueue->enqueue('o');
        myQueue->enqueue('b');
        myQueue->enqueue('a');
        //myQueue->insert('X');

        // myQueue->insert('f');
        // myQueue->insert('o');
        // myQueue->insert('o');
        // myQueue->insert('b');
        // myQueue->insert('a');

        cout << "PEEK: " << myQueue->peek() << endl;
        cout << "REMOVE: " << myQueue->remove() << endl;
        cout << "PEEK: " << myQueue->peek() << endl;

        myQueue->printArray();

        while(!myQueue->isEmpty()){
            cout << "REMOVE: " << myQueue->remove() << endl;
        }
        //cout << "PEEK: " << myQueue->peek() << endl;
        myQueue->printArray();
        // myQueue->insert('G');
        // myQueue->insert('H');
        // myQueue->insert('G');
        // myQueue->insert('H');
        // myQueue->insert('G');
        //myQueue->insert('H');
        myQueue->printArray();
    }
    catch(runtime_error &excpt){
        cerr << excpt.what() << endl;
    }
    delete myQueue;
    return 0;
}