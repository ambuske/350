#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include <iostream>
using namespace std;
#include "Model.h"

class Translator{
    public:
        Translator(); //default constructor
        ~Translator(); //destructor

        string translateEnglishWord(string word); //takes in string and returns string
        string translateEnglishSentence(string sentence); //takes in string and returns string
    private:

        Model *myModel; //instance of Model myModel
};


#endif