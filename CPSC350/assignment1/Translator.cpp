#include "Translator.h"
#include "Model.h"

//default constructor
Translator::Translator(){
    myModel=new Model(); //creating instance of Model class to reference
}
//deconstructor
Translator::~Translator(){
    delete[] myModel; //deleting instance of Model
}

string Translator::translateEnglishWord(string word){ //takes in a string word
    string kword; //creates string kword
    for (int i=0; i<word.length(); ++i){ //loops through each character of string word
        char a = word[i];
        if (myModel->isVowel(a)){ //references the isVowel method in Model and returns a true or false
            kword+= myModel->translateSingleVowel(a); //if true will then translate character using translateSingleVowel under Model
        }else{
            kword+= myModel->translateSingleConsonant(a); //if element of string is not a vowel it has to be a consonant so it will be translated under model translateSingleConsonant
        }
    }
    return kword; //returns new word with appended letters
}

string Translator::translateEnglishSentence(string sentence){ //takes in a string sentence
    string kword; //creates string kword
    for (int i=0; i<sentence.length(); ++i){ //loops through each character of string sentence
        char a = sentence[i];
        if (myModel->isVowel(a)){ //returns true or false if the character is a vowel
            kword+= myModel->translateSingleVowel(a); //if true is returned the character will be translated with translateSingleVowel in Model
        }else if(!myModel->isVowel(a) && isalpha(a)){ //if the character is not a vowel and is part of the alphabet then it has to be a consonant
            kword+= myModel->translateSingleConsonant(a); //the character will be translated with translateSingleConsonant in Model
        }else{ //if the character is not a vowel or consonant then it has to be a space or punctuation
            kword+=a; //these are not translated, just added to string
            
        }
    }
    return kword; //return new string!
}