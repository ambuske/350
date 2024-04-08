#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}
SingleLinkedList::~SingleLinkedList(){
    //"build some character"
}
void SingleLinkedList::insertFront(int d){
    ListNode *node = new ListNode(d);
    if(isEmpty()){
        back = node;
    }else{
        node->next = front;
    }
    front=node;
    size++;
}
void SingleLinkedList::insertBack(int d){
    ListNode *node = new ListNode(d);
    if(isEmpty()){
        front=node;
    }else{
        back->next = node;
    }
    back = node;
    size++;
}
bool SingleLinkedList::isEmpty(){
    return(size==0);
}
unsigned int SingleLinkedList::getSize(){
    return size;
}
int SingleLinkedList::removeFront(){
    if(isEmpty()){
        cerr<<"list is empty"<<endl;
        return -1;
    }
    int temp = front->data;
    ListNode *ft = front;

    front = front->next;
    ft->next=NULL;
    delete ft;

    size--;
    return temp;
}
int SingleLinkedList::removeBack(){
    if(isEmpty()){
        cerr<<"list is empty"<<endl;
        return -1;
    }
    int temp = back->data;
    ListNode *ft = back;

    back = back->next;
    ft->next=NULL;
    delete ft;

    size--;
    return temp;
}
int SingleLinkedList::find(int value){
    int pos = -1;
    ListNode *curr = front;
    while(curr != NULL){
        ++pos;
        if(curr->data == value)
            break;
        
        curr = curr->next;
    }
    if(curr ==NULL)
        pos = -1;
    return pos;
}
int SingleLinkedList::deleteAtPos(int pos){
    if(isEmpty()||pos<0){
        cerr<<"invalid position or empty list"<<endl;
        return -1;
    }
    int idx =0;
    ListNode *curr = front; //updating pointers
    ListNode *prev = front;

    while(idx!=pos){
        prev = curr;
        curr = curr->next;
        idx++;
    }
    //check if front
    //check if back
    //else it is between front or back
    if(curr==front){
        front = curr->next;
    }else if(curr==back){
        back = prev;
    }else{
        prev->next = curr->next; //between front and back
    }
    
    curr->next=NULL;
    int temp = curr->data;
    size--;
    delete curr;
    return temp;
}