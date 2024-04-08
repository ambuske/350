#include "LinkedList.h"

LinkedList::LinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}

LinkedList::~LinkedList(){
    //"lol research it"
    //there is some sort of looping mechanism in here
}
void LinkedList::insertFront(int d){
    ListNode *node = new ListNode(d);
    if(isEmpty()){
        back =node;
    }else{
        //not empty...
        node->next = front;
        front->prev = node;
    }
    front = node;
    ++size;
}
void LinkedList::insertBack(int d){
    ListNode *node = new ListNode(d);
    if(isEmpty()){
        front = node;
    }else{
        back->next =node;
        node->prev=back;
    }
    back = node;
    ++size;
}

int LinkedList::removeFront(){
    if(isEmpty()){
        throw runtime_error("list is empty");
    }
    ListNode *temp =front;
    if((front->next)==NULL){
        //one node in list
        back=NULL;
    }else{
        //more than one node in the list
        front->next->prev=NULL; //the fronts next pointers previous is null
    }
    front=front->next;
    temp->next=NULL;
    int data=temp->data;
    --size;
    delete temp;
    return data;
}
int LinkedList::removeBack(){
    if(isEmpty()){
        throw runtime_error("list is empty");
    }
    ListNode *temp = back;
    if((back->prev) == NULL){
        front =NULL;
    }else{
        back->prev->next =NULL;
    }
    back=back->prev;
    temp->prev=NULL;
    int data = temp->data;
    --size;
    delete temp;
    return data;

}
int LinkedList::find(int value){
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
int LinkedList::removeNode(int value){
    if(isEmpty()){
        throw runtime_error("list is empty");
    }
    ListNode *curr = front;
    while(curr->data != value){
        curr=curr->next;
        if(curr==NULL)
            return -1;
    }
    //if we make it here then we found the node that needs to be deleted
    if (curr==front){
        front = curr->next;
        front->prev=NULL;
    }
    if(curr==back){
        back=curr->prev;
        back->next = NULL;
    }
    if(curr!=front && curr!=back){ //in the middle!
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
    }
    curr->next=NULL;
    curr->prev=NULL;
    int temp = curr->data;
    --size;
    delete curr;
    return temp;
}
unsigned int LinkedList::getSize(){
    return size;
}
bool LinkedList::isEmpty(){
    return(size==0);
}
int LinkedList::getFront(){
    
}
void LinkedList::printList(bool printLink){
    ListNode *curr = front;
    while(curr!=0){
        if(curr != 0){
            cout<<"{front}: ";
            cout<<" [PREV: "<< (curr-1)<<" || "<<curr<< "|| NEXT: "<<curr+1<<" ]"<<endl;
            //curr--;
        }
        curr--;
    }
    curr--;
}