#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListNode.h"

//doubly linked list
class LinkedList{
    private:
        ListNode *front;
        ListNode *back;
        unsigned int size;
    public:
        LinkedList();
        ~LinkedList();
        void insertFront(int d);
        void insertBack(int d);
        int removeFront();
        int removeBack();
        int removeNode(int value);
        int find(int value);
        bool isEmpty();
        unsigned int getSize();
        void printList(bool isPrintLink);
};

#endif