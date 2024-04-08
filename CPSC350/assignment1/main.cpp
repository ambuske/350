#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
#include <exception>

//the main method that creates a file processor called fp that is an instance of the FileProcessor class
int main(){
    //included a try/catch for any runtime errors 
    try{
        FileProcessor fp;
        fp.processFile("original.txt", "translated.html"); //calls the method processFile within FileProcessor with two file names. the input and output file
    }catch(runtime_error &expt){ 
        cout<<expt.what()<<endl;
    }
    return 0; //have to return 0 in main methood!
}