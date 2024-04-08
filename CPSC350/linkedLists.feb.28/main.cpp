#include "ListNode.h"
#include "SingleLinkedList.h"

int main(int argc, char **argv){
    SingleLinkedList *sll = new SingleLinkedList();
    sll->insertFront(4);
    sll->insertFront(44);
    sll->insertBack(65);

    cout<<"FIND: "<<sll->find(65)<<endl;
    while(!sll->isEmpty()){
        cout<<sll->removeFront()<<endl;
    }
    sll->removeFront();
    delete sll;
    return 0;
}