#include "Level.h"


Level::Level(){

}
Level::Level(int n){
    this->n=n;
    myArray = new char*[n]; // making a new array 
    for(int i = 0; i <n; i++){
        myArray[i] = new char[n]; // looping though the array 

    }
}
Level::~Level(){ // destructor

}
void Level::populate(double c, double x, double g, double k, double m){ // populating the array 

  double n2 = n*n; // multiplying the number by itself to find the total number in the array
  double cnum = c/100;
  cnum = cnum*n2;
  double xnum = x/100;
  xnum = xnum*n2;
  double gnum = g/100;
  gnum = gnum*n2;
  double knum = k/100;
  knum = knum*n2;
  double mnum = m/100;
  mnum = mnum*n2; // taking in the number and turning it into a percentage by diving it by 100 so it knowsnthe excat number of how many spaces in the array should be populated.  

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){ // loppong though the double array 
      int randy =rand()%5; // doing randy 5 becaosue the array coukdl be populated with 5 differnt types 
      switch(randy){
        case 0:
          if(cnum>0){
            myArray[i][j] = 'C'; // populating the arrys with C
            cnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 1: 
          if(xnum>0){
            myArray[i][j] = 'x'; // populating the arrys with X
            xnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 2:
          if(gnum>0){
            myArray[i][j] = 'g'; // populating the arrys with g
            gnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 3:
          if(knum>0){
            myArray[i][j] = 'k'; // populating the arrys with k
            knum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 4:
          if(mnum>0){
            myArray[i][j] = 'm'; // populating the arrys with m
            mnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        default:
            myArray[i][j]='x'; // populating the arrys with x
            break;
      }
    }
  }
      int randyi =rand()%n;
      int randyj = rand()%n;
      myArray[randyi][randyj]= 'B'; // taking in 2 random numbers and populating it with B for boss so its outside the loop
      int randyi2 =rand()%n;
      int randyj2 = rand()%n;
      myArray[randyi2][randyj2]= 'W'; // taking in 2 ranomf numbers anf populating it owth W becaoue it's outside the loop 

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<myArray[i][j]<<" "; // adding space
    }
    cout<<endl;
  }
  cout<<"==========="<<endl;
}
void Level::populateLastLevel(double c, double x, double g, double k, double m){ // populating the last level in the array 
  double n2 = n*n;
  double cnum = c/100;
  cnum = cnum*n2;
  double xnum = x/100;
  xnum = xnum*n2;
  double gnum = g/100;
  gnum = gnum*n2;
  double knum = k/100;
  knum = knum*n2;
  double mnum = m/100;
  mnum = mnum*n2; // again taking int the numbers anf diving them by 100 to find the excat number of spaces in the arrayto pupluate

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){// looping thought the last level and populating it 
      int randy =rand()%5;
      switch(randy){
        case 0:
          if(cnum>0){
            myArray[i][j] = 'C'; // populating the last level with C
            cnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 1: 
          if(xnum>0){
            myArray[i][j] = 'x'; // populating the last level with x
            xnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 2:
          if(gnum>0){
            myArray[i][j] = 'g'; // populating the last level with g
            gnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 3:
          if(knum>0){
            myArray[i][j] = 'k'; // populating the last level with k
            knum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 4:
          if(mnum>0){
            myArray[i][j] = 'm';// populating the last level with m
            mnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        default:
            myArray[i][j]='x'; // the defult is nothing so an X
            break;
      }
    }
  }
      int randyi =rand()%n;
      int randyj = rand()%n;
      myArray[randyi][randyj]= 'B'; // getting 2 random numbers that are goign to be the new spaces in the array
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<myArray[i][j]<<" "; // adding a space 
    }
    cout<<endl;
  }
  cout<<"==========="<<endl;

}

char Level::access(int x, int y){
  return myArray[x][y]; // getting a random place in the array 
}

void Level::removeTile(int x, int y){
  myArray[x][y] = 'x'; // removeing whats in a tile and replecing it with just x for nothing
}


void Level::MarioPos(int x, int y){
  myArray[x][y]='H'; // this is where mario is on the array 
}

void Level::printArray(int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){ // lopping though the array and printing it 
      cout<<myArray[i][j]<<" "; // adding a space
    }
    cout<<endl;
  }
  cout<<"==========="<<endl; 

}

void Level::printMario(int n, int x, int y){
  char temp = myArray[x][y]; // we replace the position with mario 
  myArray[x][y]='H';
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){ // lopping though the array 
      cout<<myArray[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"==========="<<endl; 
  myArray[x][y]=temp; // prints the entire array with mario 
}