#include "Level.h"
#include <exception>
#include "World.h"
#include "Mario.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){

  try{
    int L; //levels
    int N; //dimension
    int V; //lives
    double cp; //coins percentage
    double np; //nothing percentage
    double gp; //goomba percentage
    double kp; //koopa percentage
    double mp; //mushroom percentage
    string inputFile="input.txt"; //naming input file 
    string outputFile ="MarioOutput.txt"; //naming output file

    ifstream myFile(inputFile); //assigns input file to myFile
    ofstream outfile(outputFile); //assigns output file to outfile
    streambuf *coutbuf = cout.rdbuf(); // Save cout buffer
    cout.rdbuf(outfile.rdbuf()); // Redirect cout to output file


      string line; 
      getline(myFile, line);
      L = stoi(line); //first line is levels
      getline(myFile, line);
      N= stoi(line); //second line is dimension
      getline(myFile, line);
      V= stoi(line); //third line is lives
      getline(myFile, line);
      cp = stod(line); //fourth line is coins percentage
      getline(myFile, line);
      np = stod(line); //fifth line is nothing percentage
      getline(myFile, line);
      gp = stod(line); //sixth line is goomba percentage 
      getline(myFile, line);
      kp = stod(line); //seventh line is koopa percentage
      getline(myFile, line);
      mp = stod(line); //eigth line is mushroom percentage 

    Mario myMario(N); //creating mario with the dimension
    myMario.newGame(V, L,N,cp,np,gp,kp,mp); //creating a new game with all variables 

  //  inputFile.close();
  cout.rdbuf(coutbuf); // Restore cout to console

    outfile.close(); // Close output file
  }catch(runtime_error &expt){ //catches any error
    cout<<expt.what()<<endl;
  } 
  cout << "Program completed" << endl; //prints program completed 
  return 0;
}   
