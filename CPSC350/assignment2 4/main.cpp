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
    string inputFile="input.txt";
    string outputFile ="MarioOutput.txt";

    ifstream myFile(inputFile);
    ofstream outfile(outputFile);
    streambuf *coutbuf = cout.rdbuf(); // Save cout buffer
    cout.rdbuf(outfile.rdbuf()); // Redirect cout to output file

   
    string line; 
      getline(myFile, line);
      L = stoi(line);
      getline(myFile, line);
      N= stoi(line);
      getline(myFile, line);
      V= stoi(line);
      getline(myFile, line);
      cp = stod(line);
      getline(myFile, line);
      np = stod(line);
      getline(myFile, line);
      gp = stod(line);
      getline(myFile, line);
      kp = stod(line);
      getline(myFile, line);
      mp = stod(line);
    
    Mario myMario(N);
    myMario.newGame(V, L,N,cp,np,gp,kp,mp);

  //  inputFile.close();
  cout.rdbuf(coutbuf); // Restore cout to console

    outfile.close(); // Close output file
  }catch(runtime_error &expt){
    cout<<expt.what()<<endl;
  } 
  cout << "Program completed" << endl;
  return 0;
}   
