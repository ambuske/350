#include "LinkedList.h"
#include <exception>

int main(){
    LinkedList *dll = new LinkedList();
    try{
        dll->insertFront(3);
        dll->insertFront(8);
        dll->insertBack(8);
        dll->insertBack(1);
        dll->insertFront(2);
        dll->printList(false); //if true will be memory addresses poitners
        dll->removeBack();
        cout<<"size:"<<dll->getSize()<<endl;
    }catch(runtime_error &expt){
        cout<<expt.what()<<endl;
    }
    return 0;
};