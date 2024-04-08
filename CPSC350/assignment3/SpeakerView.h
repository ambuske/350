#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include<iostream>
#include <exception>
#include <fstream>
#include <string>
using namespace std;


class SpeakerView{
    public:
        //SpeakerView();
        SpeakerView(string myFile);
        ~SpeakerView();
        //void openFile();
        int numRows();
        int numCols(string myLine);

    private:
        int N;
        int P;
        string fileName;
        double** myArray;
        ifstream inFile;


};



#endif