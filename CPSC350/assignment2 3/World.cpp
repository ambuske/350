#include "World.h"
#include <exception>
#include <cstdlib>
#include "Level.h"

//using namespace std;

World::World(){
}

World::~World(){
    delete[] newLevel;
}

void World::newWorld(int lives, int numLevel, int n, double c, double x, double g, double k, double m, int locx, int locy){


    int coins =0;
    int power =1;
    

  newLevel = new Level[numLevel];
    for(int j=0; j<numLevel-1; j++){
      newLevel[j] = Level(n);
      cout<<"Level "<<j<<endl;
        newLevel[j].populate(c, x, g, k, m);

    }
    cout<<"Level "<<numLevel-1<<endl;

    newLevel[numLevel-1]=Level(n);
    newLevel[numLevel-1].populateLastLevel(c,x, g, k, m);
    bool alive = false;
    bool gameWon = false;
    cout<<"Mario is at starting postition: ("<<locx<<","<<locy<<")"<<endl;
    cout<<"============"<<endl;
while(alive!=true){
    
    int moves = 0;
    if(lives<=0){
        alive=true;
    }
    for(int i = 0; i < numLevel; i++){
        int ogx = locx;
        int ogy = locy;
        string output;
        newLevel[i].printMario(n, locx, locy);
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

    char A = newLevel[i].access(locx, locy);
    int randy;
    switch(A){
        case 'x':
            cout<<". The position is empty. ";
            moves++;

            randy = rand()%100;
            if(randy>49){
                locy = nextY(locy, n);
            }else{
                locx = nextX(locx, n);      
            }  
            break;
        case 'm':
            cout<<". Mario ate a mushroom. ";
            moves++;
            power++;

            newLevel[i].removeTile(locx, locy);
            randy = rand()%100;
            if(randy>49){ 
                locy = nextY(locy, n);
            }else{
                locx = nextX(locx, n);   
            }
            break;
        case 'k':
            moves++;
            if(isKoopa(locx, locy)==true){
                cout<<". Mario fought a Koopa and won. ";
                newLevel[i].removeTile(locx, locy);
            }else{
                cout<<". Mario fought a Koopa and lost. ";
                power--;

            }
            randy = rand()%100;
            if(randy>49){
                locy = nextY(locy, n);
            }else{
                locx = nextX(locx, n);
            }
            break;
        case 'g':
            moves++;
            if(isGoomba(locx, locy)==true){
                cout<<". Mario fought a Goomba and won. ";
                newLevel[i].removeTile(locx, locy);
            }else{
                cout<<". Mario fought a Goomba and lost. ";
                power--;

            }
            randy = rand()%100;
            if(randy>49){
                locy = nextY(locy, n);
            }else{
                locx = nextX(locx, n);
            }
            break;
        case 'C':
            cout<<". Mario collected a coin. ";
            moves++;
            coins++;
            newLevel[i].removeTile(locx, locy);
            randy = rand()%100;
            if(randy>49){
                locy = nextY(locy, n);
            }else{
                locx = nextX(locx, n);
            }
            break;
        case 'W':
            moves++;
            D = true;
            int randyY, randyX;
            randyX = rand()%n;
            randyY = rand()%n;
            locx=randyX;
            locy=randyY;
            cout<<". Mario found a warp pipe. ";
            cout<<" Mario will WARP. ";
            break;
        case 'B':
            moves++;
            if(isBoss(locx, locy)==true){
                cout<< ". Mario encountered a boss and won. ";
                newLevel[i].removeTile(locx, locy);
                if(i==(numLevel-1)){
                    cout<<  " Mario has saved the princess. ";
                    gameWon = true;
                    alive = true;
                    D=true;
                
                }else{
                    cout<<  " He will move on to the next level. ";
                    D=true;

                }
            }else{
                cout<<  ". Mario encountered a boss and lost. ";
                power--;
                power--;
                if(power>0){
                    cout<< " Mario will stay put and fight the boss again. ";
                }else if(lives>0){
                    cout<< " Mario will stay put and fight the boss again. ";
                }
            }
            break;
    




    }


    cout<<"Mario has "<<lives<<" lives left. Mario has "<<coins<<" coins."<<endl;
    cout<<"============"<<endl;
    newLevel[i].printMario(n, locx, locy);
    if(power>3){
        power=2;
    }
    if(power<0){
        power = 0;
        lives--;
    }if(coins>=20){
        coins=coins-20;
        lives++;
    }
    if(lives<=0){
        lives = 0;
        D=true;
        alive = true;
        death1 = " Mario has run out of lives.";
        break;
    }
    }

    }
    if(gameWon==true){
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
    int Grandy = rand()%4;
    if(Grandy<4){
        return true;
    }else{
        return false;
    }
}

bool World::isKoopa(int Kx, int Ky){
    int Krandy = rand()%99;
    if(Krandy<65){
        return true;
    }else{
        return false;
    }
}

bool World::isBoss(int bx, int by){
    int Brandy = rand()%100;
    if(Brandy>50){
        return true;

    }else{
        return false;
    }
}



int World::nextX(int x, int n){
    int r;
    int randy = rand()%1;
    switch (randy){
    case 0:
        if(x<n-1){
          r=x+1;
        }else{
          r=0;
        }
        break;
    case 1:
        if(x>0){
          r=x-1;
        }else{
          r=n-1;
        }
        break;
    
}
  return r;
}
int World::nextY(int y, int n){
  int r;
    int randy = rand()%1;
    switch (randy){
    case 0:
        if(y<n-1){
            r= y+1;
        }else{
            r= 0;
        }
        break;
    case 1:
        if(y>0){
            r= y-1;
        }else{
            r= n-1;
        }
        break;
}
  return r;
}

