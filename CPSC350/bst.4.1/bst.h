#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template<class T>
class TreeNode{
    public:
        TreeNode(); //default constructor
        TreeNode(T k); //overloaded constructor
        virtual ~TreeNode();  //destructor

        T key;
        TreeNode<T> *left;
        TreeNode<T> *right;

    private:

};

template<class T>
TreeNode<T>::TreeNode(){
    left=NULL;
    right=NULL;
    key=NULL;
}

template<class T>
TreeNode<T>::TreeNode(T k){
    left=NULL;
    right=NULL;
    key=k;
}

template<class T>
TreeNode<T>::~TreeNode(){
    left = NULL;
    right = NULL;
}

template <class T>
class BST{
    public:
        BST(); // default constructor
        virtual ~BST(); //destructor

        void insert(T value);
        bool constains(T value); //search method
        bool deleteNode(T k);
        TreeNode<T> *getSuccessor(TreeNode<T> *d); //use to delete node

        bool isEmpty();
        T* getMin();
        T* getMax();

        void printTree();
        void recPrint(TreeNode<T> *node);

    private:
        TreeNode<T> *root;

};

template <class T>
BST<T>::BST(){
    root = NULL;
}

template <class T>
BST<T>::~BST(){
    //"build some character, its good for you"
}

//preorder traversal to print out the tree
template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
    if(node == NULL){
        return;
    }
    cout<<node->key<<endl;
    recPrint(node->left);
    recPrint(node->right);

    //for in order:
    // recPrint(node->left);
    // cout<<node->key<<endl;
    // recPrint(node->right);
}

template <class T>
void BST<T>::printTree(){
    recPrint(root);
}

template <class T>
bool BST<T>::isEmpty(){
    return (root == NULL);
}

template <class T>
T* BST<T>::getMin(){
    if(isEmpty()){
        return NULL;
    }
    TreeNode<T> *current =root;
    while(current->left != NULL){
        current = current->left;
    }
    return &(current->key); //returning pointer address at point
}

template <class T>
T* BST<T>::getMax(){
    if(isEmpty()){
        return NULL;
    }
    TreeNode<T> *current =root;
    while(current->right != NULL){
        current = current->right;
    }
    return &(current->key); //returning pointer address at point
}

#endif