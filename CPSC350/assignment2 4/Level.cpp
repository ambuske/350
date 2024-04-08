#include "Level.h"


Level::Level(){

}
Level::Level(int n){
    this->n=n;
    myArray = new char*[n];
    for(int i = 0; i <n; i++){
        myArray[i] = new char[n];

    }
}
Level::~Level(){

}
void Level::populate(double c, double x, double g, double k, double m){

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
  mnum = mnum*n2;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      int randy =rand()%5;
      switch(randy){
        case 0:
          if(cnum>0){
            myArray[i][j] = 'C';
            cnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 1: 
          if(xnum>0){
            myArray[i][j] = 'x';
            xnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 2:
          if(gnum>0){
            myArray[i][j] = 'g';
            gnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 3:
          if(knum>0){
            myArray[i][j] = 'k';
            knum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 4:
          if(mnum>0){
            myArray[i][j] = 'm';
            mnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        default:
            myArray[i][j]='x';
            break;
      }
    }
  }
      int randyi =rand()%n;
      int randyj = rand()%n;
      myArray[randyi][randyj]= 'B';
      int randyi2 =rand()%n;
      int randyj2 = rand()%n;
      myArray[randyi2][randyj2]= 'W';

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<myArray[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"==========="<<endl;
}
void Level::populateLastLevel(double c, double x, double g, double k, double m){
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
  mnum = mnum*n2;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      int randy =rand()%5;
      switch(randy){
        case 0:
          if(cnum>0){
            myArray[i][j] = 'C';
            cnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 1: 
          if(xnum>0){
            myArray[i][j] = 'x';
            xnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 2:
          if(gnum>0){
            myArray[i][j] = 'g';
            gnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 3:
          if(knum>0){
            myArray[i][j] = 'k';
            knum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        case 4:
          if(mnum>0){
            myArray[i][j] = 'm';
            mnum--;
          }else{
            myArray[i][j]='x';
          }
          break;
        default:
            myArray[i][j]='x';
            break;
      }
    }
  }
      int randyi =rand()%n;
      int randyj = rand()%n;
      myArray[randyi][randyj]= 'B';
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<myArray[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"==========="<<endl; 

}

char Level::access(int x, int y){
  return myArray[x][y];
}

void Level::removeTile(int x, int y){
  myArray[x][y] = 'x';
}


void Level::MarioPos(int x, int y){
  myArray[x][y]='H';
}

void Level::printArray(int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<myArray[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"==========="<<endl; 

}

void Level::printMario(int n, int x, int y){
  char temp = myArray[x][y];
  myArray[x][y]='H';
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<myArray[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"==========="<<endl; 
  myArray[x][y]=temp;
}