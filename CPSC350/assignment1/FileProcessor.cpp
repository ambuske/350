#include "FileProcessor.h"
#include "Translator.h"
#include <fstream>
#include <sstream>

//default constructor
FileProcessor::FileProcessor(){ 
    myTranslator = new Translator(); //new instance of Translator
}
//deconstructor
FileProcessor::~FileProcessor(){
    delete[] myTranslator; //deleting instance of translator
}

void FileProcessor::processFile(string inputFile, string outputFile){ //takes in two strings that will be file names
    ifstream inFile(inputFile); // assigns inFile to the inputFile
    ifstream inFile2(inputFile); //assigns inFie2 to the inputFile
    ofstream outFile(outputFile); //assigns outFile to the outputFile
    stringstream forHtml; //creating a string that can be put into the html
    //creating the head documentation and title for the html
    forHtml<<"<!DOCTYPE html>\n<html>\n<head>\n<title>English to Robber Translation</title>\n</head>\n<body>\n";


    string line; //new string for lines
    
    while(getline(inFile, line)){ //loops through each line of file
        forHtml<<"<p><b>"<<line<<"</b><br/></p>"<<endl; //this loop repeats all the lines that the original file had
    }
    forHtml<<"<p><b></b><br></p>"<<endl; //the html syntax between the normal writing and translated
    while(getline(inFile2, line)){ //another for loop going through the input file again
        string translated = myTranslator->translateEnglishSentence(line); //calling myTranslator to translate each line
        forHtml<<"<p><i>"<<translated<<"</i><br></p>"<<endl; //putting the translated lines into the html
        translated.clear(); //clearing/deleting the translated string
    }
    

    forHtml<<"<p><i></i><br></p>\n</body>\n</html>"; //the ending syntax for html 

    outFile<<forHtml.str(); //adding our forHtml to the outFile

    //closing all the files
    inFile.close();
    outFile.close();
    inFile2.close();
}