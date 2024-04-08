#include "Model.h"

//default constructor 
Model::Model(){
    newCons=""; //declaring the newCons variable as an empty string
    cons = "o"; //Declaring a constant "o" to be added to constonants
}
//deconstructor
Model::~Model(){

}
//takes in a character and determines whether or not it is a vowel
bool Model::isVowel(char l){
        l=tolower(l); //makes the letter lowercase
        if (l=='a'||l=='e'||l=='i'||l=='o'||l=='u'){ //compares to all lowercase vowels
            return true;
        }else{
            return false;
        }
        //returns true or false depending on whether letter is vowel or not
}
//takes in a character
string Model::translateSingleConsonant(char consonant){
    newCons.clear(); //clears the newCons variable
    newCons+=consonant+cons+consonant; //adds the given consonant character, our "o" variable and the constonant character again
    
    return newCons; //returns the new string 
    
}
//takes in a character
string Model::translateSingleVowel(char vowel){
    newCons.clear(); //clears the newCons variable
    return(newCons+=vowel); //adds the vowel character to our new string and returns it.
    
}