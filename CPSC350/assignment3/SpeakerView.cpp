#include "SpeakerView.h"
#include <fstream>
#include <sstream>
#include <iostream>



SpeakerView::SpeakerView(string myFile){
    fileName = myFile;
    inFile.open(myFile);

}

SpeakerView::~SpeakerView(){

}

int SpeakerView::numRows(){
    string line;
    while(getline(inFile, line)){
        N++;
        numCols
    }
}

int SpeakerView::numCols(string myLine){

}

// void SpeakerView::openFile(){
//     ifstream inFile(fileName);
//     string line;
//     while(getline(inFile, line)){
//         N++;
//         stringstream ss(line);

        

//     }
// }