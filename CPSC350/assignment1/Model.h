#ifndef MODEL_H
#define MODEL_H
#include <iostream>
using namespace std;


class Model{
    public:
        Model(); //default constructor
        ~Model(); //destructor
    
        string translateSingleConsonant(char consonant); //takes in character, returns string
        string translateSingleVowel(char vowel); //takes in character, returns string

        bool isVowel(char l); //takes in character, returns true or false

    private:
        string newCons; //string that we will add characters to and return
        string cons; //the string we will define as "o"
    
};
#endif