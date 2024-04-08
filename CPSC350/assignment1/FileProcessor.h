#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include <iostream>
#include "Translator.h"
using namespace std;

class FileProcessor{
    public:
        FileProcessor(); //default constructor
        ~FileProcessor(); //destructor

        void processFile(string inputFile, string outputFile); //takes in two strings that will be the the name of the inputFile and output file
    private:
        Translator *myTranslator; //creating instance of Translator called myTranslator
};



#endif