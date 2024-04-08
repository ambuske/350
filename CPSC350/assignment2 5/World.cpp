#include "World.h"
#include <exception>
#include <cstdlib>
#include "Level.h"


World::World(){
}

World::~World(){
    delete[] newLevel; // deleting the newLevel
}

void World::newWorld(int lives, int numLevel, int n, double c, double x, double g, double k, double m, int locx, int locy){
    int defeatedEnemy = 0; // setting the defeated enemies to 0

    int coins =0; // intializing the starting value for coins
    int power =1; // intializing the starting value for power 


  newLevel = new Level[numLevel]; // creating a new level array
    for(int j=0; j<numLevel-1; j++){
      newLevel[j] = Level(n);
      cout<<"Level "<<j<<endl;
        newLevel[j].populate(c, x, g, k, m); // poulating the new array with the values from the input file

    }
    cout<<"Level "<<numLevel-1<<endl;

    newLevel[numLevel-1]=Level(n);
    newLevel[numLevel-1].populateLastLevel(c,x, g, k, m); // poulating the last level
    bool alive = false; // setting the bool alive to flase
    bool gameWon = false; // setting the bool gameWon to flase
    cout<<"Mario is at starting postition: ("<<locx<<","<<locy<<")"<<endl; // giving Mario a starting location
    cout<<"============"<<endl;
while(alive!=true){ // creating a while loop based on while mario is alive 

    int moves = 0;
    if(lives<=0){
        alive=true;
    }
    for(int i = 0; i < numLevel; i++){
        int ogx = locx;
        int ogy = locy; // giving mario a ranodm location on the baord
        string output;
        newLevel[i].printMario(n, locx, locy); // printing the array with mario
        D=false;
        string death;
        string death1;
    while(D!=true){
        if(power>=3){
        power=2;
    }
    cout<<"Level: "<<i<<". Mario is at position: ("<<locx<<","<<locy<<"). Mario is at power level "<<power;
    //<<death<<". Mario has "<<lives<<" lives left. Mario has "<<coins<<" coins."<<death1<<endl;
    //cout<<"============"<<endl;

    char A = newLevel[i].access(locx, locy); // getting mario at a level anf getting a location for him 
    int randy;
    int X1;
    int Y1;
    string marioD;
    switch(A){ // using a switch stament to take in the tile where mario lands 
        case 'x': // if the tile is x then nothing happens 
            X1=locx;
            Y1=locy;
            cout<<". The position is empty. ";
            moves++;

            randy = rand()%100;
            if(randy>49){
                locy = nextY(locy, n);
            }else{
                locx = nextX(locx, n);      
            }  
            marioD = direction(X1, Y1, locx, locy); // changing marios location
            break;
        case 'm': // if he lands on a mushrrom his power increase
            X1=locx;
            Y1=locy;
            cout<<". Mario ate a mushroom. ";
            moves++;
            power++;

            newLevel[i].removeTile(locx, locy); // we remove the mushroom tile and replace it with nothing and mario countiunes on 
            randy = rand()%100;
            if(randy>49){ 
                locy = nextY(locy, n);
            }else{
                locx = nextX(locx, n);   
            }
            marioD = direction(X1, Y1, locx, locy);
            break;
        case 'k': // if he lands on a Koopa marrio has to fight it 
            X1=locx;
            Y1=locy;
            moves++;
            if(isKoopa(locx, locy)==true){
                cout<<". Mario fought a Koopa and won. ";
                newLevel[i].removeTile(locx, locy); // if marrio beats the koopa he continues on
              defeatedEnemy++; // adding to the defeated enemies
            }else{
                cout<<". Mario fought a Koopa and lost. ";
                power--; // if marrio loses to the koopa he losses a power

            }
            randy = rand()%100;
            if(randy>49){ // marrio moves to a random location 
                locy = nextY(locy, n);
            }else{
                locx = nextX(locx, n);
            }
            marioD = direction(X1, Y1, locx, locy);
            break;
        case 'g': // if marrio lands on a gommpa he has to fight it 
            X1=locx;
            Y1=locy;
            moves++;
            if(isGoomba(locx, locy)==true){
                cout<<". Mario fought a Goomba and won. ";
                newLevel[i].removeTile(locx, locy); // if he wins he gets the tile is removed and he moves on 
              defeatedEnemy++; // adding to the defeated enemies
            }else{
                cout<<". Mario fought a Goomba and lost. ";
                power--; // if he losses is power decresses

            }
            randy = rand()%100;
            if(randy>49){ // he then moves to another random location 
                locy = nextY(locy, n);
            }else{
                locx = nextX(locx, n);
            }
            marioD = direction(X1, Y1, locx, locy);
            break;
        case 'C': // if he lands on a C that meanss mario gets a coin and his coin count goes up 
            X1=locx;
            Y1=locy;
            cout<<". Mario collected a coin. ";
            moves++;
            coins++;
            newLevel[i].removeTile(locx, locy); // the time is then removes and mario moves on 
            randy = rand()%100;
            if(randy>49){
                locy = nextY(locy, n);
            }else{
                locx = nextX(locx, n);
            }
            marioD = direction(X1, Y1, locx, locy);
            break;
        case 'W': // if he lands on a w he lands on a wrapipe 
            X1=locx;
            Y1=locy;
            moves++;
            D = true;
            int randyY, randyX;
            randyX = rand()%n;
            randyY = rand()%n;
            locx=randyX;
            locy=randyY;
            cout<<". Mario found a warp pipe. ";
            cout<<" Mario will WARP. ";
            marioD = direction(X1, Y1, locx, locy);
            break;
        case 'B': // if he lands on a B that menas mario lands on the boss
            X1=locx;
            Y1=locy;
            moves++;
            if(isBoss(locx, locy)==true){
                cout<< ". Mario encountered a boss and won. ";
                newLevel[i].removeTile(locx, locy); // if he beats the boss he gets a chance at saving the princess 
                if(i==(numLevel-1)){ // if he is on the last level he wins
                    cout<<  " Mario has saved the princess. ";
                    gameWon = true;
                    alive = true;
                    D=true;

                }else{
                    cout<<  " He will move on to the next level. ";
                    D=true; // if he isn't on the last level then he just moves up a level 

                }
              defeatedEnemy++; // adding to the defeated enemies
            }else{
                cout<<  ". Mario encountered a boss and lost. ";
                power--; // if he losses to the boss is power decresses by 2
                power--;
                if(power>0){
                    cout<< " Mario will stay put and fight the boss again. "; // if his power is greater then 0 he will fight the boss again
                }else if(lives>0){
                    cout<< " Mario will stay put and fight the boss again. "; // if his live count is greater then 0 he will fight the boss again
                }
            }
            marioD = direction(X1, Y1, locx, locy);
            break;





    }


    cout<<"Mario has "<<lives<<" lives left. Mario has "<<coins<<" coins."<<" Direction: "<<marioD<<endl;
    cout<<"============"<<endl; // printing out how many lives and coins and dirceation mario has 
    newLevel[i].printMario(n, locx, locy); // printing mario 
    if(power>3){
        power=2;
    }// power can not go over 2
    if(power<0){
        power = 0;
        lives--;
      if(defeatedEnemy>=7){
          lives++;
      }
    }if(coins>=20){
        coins=coins-20;
        lives++; // if he has 20 coins he gets a life and his coins are reset to 0
    }
    if(lives<=0){
        lives = 0;
        D=true;
        alive = true;
        death1 = " Mario has run out of lives.";
        break; // if he runs out of lives he dies and the game ends
    }
    }

    }
    if(gameWon==true){ // if he saves the picincess he wins the game 
        cout<<"MARIO SAVED THE PRINCESS AND WON!"<<endl;
    }else{
        cout<<"MARIO DIED AND LOST THE GAME"<<endl;
    }
    cout<<"Moves: "<<moves<<endl;
    }

    if(alive==true){
        cout<<"GAME OVER!"<<endl;

    }


}


bool World::isGoomba(int Gx, int Gy){
    int Grandy = rand()%4; // marios chances of beating the Gooba 
    if(Grandy<4){ // mario has a 80% chnace of beating the Gooba
        return true;
    }else{
        return false;
    }
}

bool World::isKoopa(int Kx, int Ky){
    int Krandy = rand()%99;
    if(Krandy<65){ // mario has a 65% chance of beating the koopa
        return true;
    }else{
        return false;
    }
}

bool World::isBoss(int bx, int by){
    int Brandy = rand()%100;
    if(Brandy>50){ // marios has a 50% chance of beating the boss
        return true;

    }else{
        return false;
    }
}



int World::nextX(int x, int n){ // randomly going to a next place on the board
    int r;
    int randy = rand()%100;
    if(randy>49){
        if(x<n-1){
          r=x+1;
        }else{
          r=0;
        }
    }else{

        if(x>0){
          r=x-1;
        }else{
          r=n-1;
        } 
    }


  return r;
}
int World::nextY(int y, int n){ // randomly going to a next place on the board
  int r;
    int randy = rand()%100;
    if(randy>49){
        if(y<n-1){
          r=y+1;
        }else{
          r=0;
        }
    }else{

        if(y>0){
          r=y-1;
        }else{
          r=n-1;
        }
    }


  return r;
}


string World::direction(int x, int y, int xx, int yy){ // marrio moving to differnt places on the board 
    if((x-xx)==1||(x-xx)<-1){
        return "UP"; // if marrio is moving up he is going up
    }else if((x-xx)==-1||(x-xx)>1){
        return "DOWN"; // if marrio is moving down he is going down
    }else if((y-yy)==1||(y-yy)<-1){
        return "LEFT";// if mario is moving left he is going left
    }else if ((y-yy)==-1||(y-yy)>1){
        return "RIGHT"; // if mario is moving right he is going right
    }else if((x-xx)==0 && (y-yy)==0){
        return "stay put";
    }
}
