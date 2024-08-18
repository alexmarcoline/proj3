// Game.cpp
//note to uncle frank to ask: why isnt dragon dropping its item
#include "Game.h"
#include "utilities.h"
#include "Actor.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define UNSEEN (-1)
int iterations;

// Implement these and other Game member functions you may have added.
Game::~Game(){
    for(int i=0; i<monsters.size();i++){
       Actor* d = monsters.back();
        monsters.pop_back();
        delete d;
    }
    

    
}
Game::Game(int goblinSmellDistance)
{map = new Map();
    player =new Player(0,0, '@', 20, 2, 2, 2, 0, 20, "Player", new Weapon(0,0, "short sword", "slashes", 0,2, false, ')'));
    goblinDistance =goblinSmellDistance;
    level = 0;
    stair = new GameObject(0,0,"staircase", "none", '>');
    goldenIdol =  new GameObject(0,0, "golden idol", "game over", '&');
    goblinD = goblinSmellDistance +1;
    
   } //makes a new game object, initalizes player, level as well as the game's objects like stairs and final object



int sign(int val){
    return (0<val) - (val<0);
}
void ::Game::newLevel(int level){ //called each time you make a new level, clears the map, generates new map, copies it to the game's grid, and clears the current monster objects and items. Places the monsters based on which level you are on
    map->clear();
    map->initialize();
    copyMap(map);
    place(player);
    if(monsters.size()!=0){
        monsters.clear();
    }
    if(items.size()!=0){
        items.clear();
        
        
    }
   
    
   
    placeObjects();
    placeMonsters(level);
    
    display();
}



void Game::placeObjects(){
    int numofScr = randInt(2,3);
    GameObject* t;
    for(int i=0; i<numofScr;i++){
        
        int whichObj = randInt(1,7);
       
        if(whichObj==1){ //short sword
            int spaces = countSpace();   //number of empty space
            int space = randInt(1,spaces); //place in map
            int placeR =0;
            int placeC =0;
            getCoordinate(space, placeR, placeC);
           // gamegrid[placeR][placeC]=goldenIdol->symbol();
            t = new Weapon(0,0, "short sword", "slashes", 0,2, false, ')');
            t->setC(placeC);
            t->setR(placeR);
            items.push_back(t);
            
        }
        if(whichObj==2){ //short sword
            int spaces = countSpace();   //number of empty space
            int space = randInt(1,spaces); //place in map
            int placeR =0;
            int placeC =0;
            getCoordinate(space, placeR, placeC);
           // gamegrid[placeR][placeC]=goldenIdol->symbol();
            t = new Weapon(0,0, "mace", "swings", 0,2, false, ')');
            t->setC(placeC);
            t->setR(placeR);
            items.push_back(t);
            
        }
        if(whichObj==3){ //short sword
            int spaces = countSpace();   //number of empty space
            int space = randInt(1,spaces); //place in map
            int placeR =0;
            int placeC =0;
            getCoordinate(space, placeR, placeC);
           // gamegrid[placeR][placeC]=goldenIdol->symbol();
            t = new Weapon(0,0, "long sword", "swings", 2,4, false, ')');
            t->setC(placeC);
            t->setR(placeR);
            items.push_back(t);
            
        }
        if(whichObj==4){
            int spaces = countSpace();   //number of empty space
            int space = randInt(1,spaces); //place in map
            int placeR =0;
            int placeC =0;
            getCoordinate(space, placeR, placeC);
           // gamegrid[placeR][placeC]=goldenIdol->symbol();
            t = new Scroll(0, 0, "scroll of improve armor", "incArmor", '?');

            t->setC(placeC);
            t->setR(placeR);
            items.push_back(t);
            
        }
        if(whichObj==5){
            int spaces = countSpace();   //number of empty space
            int space = randInt(1,spaces); //place in map
            int placeR =0;
            int placeC =0;
            getCoordinate(space, placeR, placeC);
           // gamegrid[placeR][placeC]=goldenIdol->symbol();
            t = new Scroll(0, 0, "scroll of improve strength", "incStr", '?');

            t->setC(placeC);
            t->setR(placeR);
            items.push_back(t);
            
        }
        if(whichObj==6){
            int spaces = countSpace();   //number of empty space
            int space = randInt(1,spaces); //place in map
            int placeR =0;
            int placeC =0;
            getCoordinate(space, placeR, placeC);
           // gamegrid[placeR][placeC]=goldenIdol->symbol();
            t = new Scroll(0, 0, "scroll of improve health", "incHealth", '?');

            t->setC(placeC);
            t->setR(placeR);
            items.push_back(t);
            
        }
        if(whichObj==7){
            int spaces = countSpace();   //number of empty space
            int space = randInt(1,spaces); //place in map
            int placeR =0;
            int placeC =0;
            getCoordinate(space, placeR, placeC);
           // gamegrid[placeR][placeC]=goldenIdol->symbol();
            t = new Scroll(0, 0, "scroll of improve dexterity", "incDex", '?');

            t->setC(placeC);
            t->setR(placeR);
            items.push_back(t);
            
        }
        
    }
}
void Game::placeMonsters(int level){ //helper function for new level. based on level passed in, makes a number of monsters to be generated, and generates a random number of each possible monsters and items based on level
    int numOfMonsters = randInt(2,5*(level+1)+1);
    while(numOfMonsters!=0){
        if(level ==0 || level==1 ){
            int whichM = randInt(0,1);
            if(whichM ==0){ //snakewoman
                int hp = randInt(3,6);
                SnakeWoman* j = new SnakeWoman(0,0,'S', hp ,2, 3,3,  0,"Snakewoman",(new Weapon(0,0, "magic fangs", "slashes", 0,2, false, ')' ) ));
                place(j);
                monsters.push_back(j);
                numOfMonsters--;
            }
            else{
                int hp = randInt(15,20);
                Goblin* g = new Goblin(0,0,'G', hp,1,3,1,0,"Goblin", new Weapon(0,0, "long sword", "swings", 2,4, false, ')'),  goblinD);
               
                place(g);
                monsters.push_back(g);
                numOfMonsters--;
            }
            
            int spaces = countSpace();   //number of empty space
            int space = randInt(1,spaces); //place in map
            int placeR =0;
            int placeC =0;
            getCoordinate(space, placeR, placeC);
            gamegrid[placeR][placeC]=stair->symbol();
            stair->setC(placeC);
            stair->setR(placeR);
        }
        if(level == 2){
            int spaces = countSpace();   //number of empty space
            int space = randInt(1,spaces); //place in map
            int placeR =0;
            int placeC =0;
            getCoordinate(space, placeR, placeC);
            gamegrid[placeR][placeC]=stair->symbol();
            stair->setC(placeC);
            stair->setR(placeR);
            
            int whichM = randInt(0,2);
            if(whichM ==0){
                int hp = randInt(3,6);
                SnakeWoman* j = new SnakeWoman(0,0,'S', hp ,2, 3,3,  0,"Snakewoman",(new Weapon(0,0, "magic fangs", "slashes", 0,2, false, ')' ) ));
                place(j);
                monsters.push_back(j);
                numOfMonsters--;
            }
            else if(whichM==1){
                int hp = randInt(15,20);
                Goblin* g = new Goblin(0,0,'G', hp,1,3,1,0,"Goblin", new Weapon(0,0, "long sword", "swings", 2,4, false, ')'),  goblinD);
                place(g);
                monsters.push_back(g);
                numOfMonsters--;
            } //goblin
            else if(whichM==2){ //bogeyman
                int h = randInt(5,10);
                int st = randInt(2,3);
                int dx = randInt(2,3);
                Bogeyman* m = new Bogeyman(0,0,'B', h ,2,st,dx,0,"Bogeyman", new Weapon(0,0, "short sword", "slashes", 0,2, false, ')'));
                place(m);
                monsters.push_back(m);
                numOfMonsters--;
            }
        }
        if(level==3){
            int spaces = countSpace();   //number of empty space
            int space = randInt(1,spaces); //place in map
            int placeR =0;
            int placeC =0;
            getCoordinate(space, placeR, placeC);
            gamegrid[placeR][placeC]=stair->symbol();
            stair->setC(placeC);
            stair->setR(placeR);
            
            int whichM = randInt(0,3);
            if(whichM ==0){
                int hp = randInt(3,6);
                SnakeWoman* j = new SnakeWoman(0,0,'S', hp ,2, 3,3,  0,"Snakewoman",(new Weapon(0,0, "magic fangs", "slashes", 0,2, false, ')' ) ));
                place(j);
                monsters.push_back(j);
                numOfMonsters--;
            }
            else if(whichM==1){
                int hp = randInt(15,20);
                Goblin* g = new Goblin(0,0,'G', hp,1,3,1,0,"Goblin", new Weapon(0,0, "long sword", "swings", 2,4, false, ')'),  goblinD);
                place(g);
                monsters.push_back(g);
                numOfMonsters--;
            } //goblin
            else if(whichM==2){ //bogeyman
                int h = randInt(5,10);
                int st = randInt(2,3);
                int dx = randInt(2,3);
                Bogeyman* m = new Bogeyman(0,0,'B', h ,2,st,dx,0,"Bogeyman", new Weapon(0,0, "short sword", "slashes", 0,2, false, ')'));
                place(m);
                monsters.push_back(m);
                numOfMonsters--;
            }
            else if(whichM == 3){
                int he = randInt(20,25);
                Dragon* d = new Dragon(0,0,'D',he, 4,4,4,0, "Dragon", new Weapon(0,0,"long sword", "swings", 2,4,false, '?'));
                place(d);
                monsters.push_back(d);
                numOfMonsters--;
            }
        }
        if(level==4){
            int spaces = countSpace();   //number of empty space
            int space = randInt(1,spaces); //place in map
            int placeR =0;
            int placeC =0;
            getCoordinate(space, placeR, placeC);
            gamegrid[placeR][placeC]=goldenIdol->symbol();
            goldenIdol->setC(placeC);
            goldenIdol->setR(placeR);
            
            int whichM = randInt(0,3);
            if(whichM ==0){
                int hp = randInt(3,6);
                SnakeWoman* j = new SnakeWoman(0,0,'S', hp ,2, 3,3,  0,"Snakewoman",(new Weapon(0,0, "magic fangs", "slashes", 0,2, false, ')' ) ));
                place(j);
                monsters.push_back(j);
                numOfMonsters--;
            }
            else if(whichM==1){
                
                int hp = randInt(15,20);
                Goblin* g = new Goblin(0,0,'G', hp,1,3,1,0,"Goblin", new Weapon(0,0, "long sword", "swings", 2,4, false, ')'),  goblinD);
                cout<<g->strength();
                cout<<g->dexterity();
                place(g);
                monsters.push_back(g);
                numOfMonsters--;
            } //goblin
            else if(whichM==2){ //bogeyman
                int h = randInt(5,10);
                int st = randInt(2,3);
                int dx = randInt(2,3);
                Bogeyman* m = new Bogeyman(0,0,'B', h ,2,st,dx,0,"Bogeyman", new Weapon(0,0, "short sword", "slashes", 0,2, false, ')'));
                place(m);
                monsters.push_back(m);
                numOfMonsters--;
            }
            else if(whichM == 3){
                int he = randInt(20,25);
                Dragon* d = new Dragon(0,0,'D',he, 4,4,4,0, "Dragon", new Weapon(0,0,"long sword", "swings", 2,4,false, '?'));
                place(d);
                monsters.push_back(d);
                numOfMonsters--;
            }
            
        }
    }
    
 
}
void Game::play() //games play function. game runs while player has health, not on level 5, and no 'q' to quit game. based on input(c,q,r,w,i,h,j,k,l,g' does actions and then changes the grid if wants to display. First takes in player's input, then goes through all of the monsters and takes their inputs and moves them if within range to move
{
    newLevel(0);
    
    char c = 'r';
    char r = '3';
    while(c!='q' && (player->health()>0) && level<5){
        if(randInt(1, 10)==1){
            player->changeHealth(1);
        }
        c = getCharacter();
        
        int dc = 0;
        int dr =0;
        switch(c){ //player movement
                
            default:
                break;
            case 'c':
                player->cheatP();
                break;
            case'>':
                if(player->row() == stair->row() && player->col() == stair->col()){
                    newLevel(level+1);
                    level++;
                }
                    break;
                    
                case 'h':
                    dc=-1;
                    dr=0;
                    break;
                case 'j':
                    dr=1;
                    dc=0;
                    break;
                case 'k':
                    dr=-1;
                    dc=0;
                    break;
                case 'l':
                    dc=1;
                    dr=0;
                    break;
                case'g':
                if(level == 4 && player->row() == goldenIdol->row() && player->col() == goldenIdol->col()){
                    cout << endl<<"Congratulations! You won the game!" << endl;
                    return;
                }
                else{
                    for(int i=0; i<items.size();i++){
                        if(items[i]->row() == player->row() && items[i]->col() == player->col()){
                            
                            player->pickup(items[i]);
                         
                            vector<GameObject*>::iterator it = find(items.begin(), items.end(), items[i]);
                            
                            cout<<"You pickup a "<< (*it)->name();
                            items.erase(it);
                           
                            cout<<endl;
                        }
                    }
                }
                    break;
                case 'r':
                
                player->inventory();
                r = getCharacter();
                if(player->isTeleportS(r-'a')){
                    place(player);
                    
                    player->readScroll(r-'a');
                }
                else{
                    player->readScroll(r-'a');
                }
                    break;
            case 'w':
                player->inventory();
                r = getCharacter();
                player->wield(r-'a');
                
             
                break;
                case'i':
                    clearScreen();
                    
                    player->inventory();
                    
                    getCharacter();
                    break;
                }
                if(player->sleep() ==0){ //accounts for the sleep, using the input just recieved to do action
                    if((dc!= 0 )|| (dr!= 0)){
                        if(isWall(player->row()+dr, player->col()+ dc)){ //if run into wall skip player turn
                            ;
                        }
                        else if(isMonster(player->row()+dr, player->col()+dc)){ //if you are moving to a moster square, attack them, if they die calc drop rates and drop if required
                            
                            Actor* attacked = getMonster(player->row()+dr, player->col()+dc);
                           
                            player->attack(attacked);
                            if(getMonster(player->row()+dr, player->col()+dc) ->alive() == false){
                                if(getMonster(player->row()+dr, player->col()+dc)->drop() == true){
                                    if(getMonster(player->row()+dr, player->col()+dc)->name()== "Bogeyman"){
                                        GameObject* drop =new Weapon(0,0, "magic axe", "slashes", 5,5, false, ')');
                                        drop->setC(attacked->col());
                                        drop->setR(attacked->row());
                                        items.push_back(drop);
                                    }
                                    else if (getMonster(player->row()+dr, player->col()+dc)->name()== "Goblin"){
                                        int x = randInt(1,2);
                                        if(x==1){
                                            GameObject* drop =new Weapon(0,0, "magic axe", "slashes", 5,5, false, ')');
                                            drop->setC(attacked->col());
                                            drop->setR(attacked->row());
                                            items.push_back(drop);
                                        }
                                        else if(x==2){
                                            GameObject* drop = new Weapon(0,0, "magic fangs", "slashes", 0,2, false, ')' ) ;
                                            drop->setC(attacked->col());
                                            drop->setR(attacked->row());
                                            items.push_back(drop);
                                        }
                                    }
                                    
                                    else if (getMonster(player->row()+dr, player->col()+dc)->name()== "Snakewoman"){
                             
                                        GameObject* drop =attacked->getWeapon();
                                        drop->setC(attacked->col());
                                        drop->setR(attacked->row());
                                        items.push_back(drop);
                                    }
                                    else if (getMonster(player->row()+dr, player->col()+dc)->name()== "Dragon"){
                                        
                                        int whichS = randInt(1,5);
                                       
                                        if(whichS==1){
                                            GameObject* drop = new Scroll(player->row()+dr, player->col()+dc, "scroll of teleportation", "teleport", '?');
                                            drop->setC(attacked->col());
                                            drop->setR(attacked->row());
                                            
                                            items.push_back(drop);}
                                        if(whichS==2){
                                            GameObject* drop = new Scroll(player->row()+dr, player->col()+dc, "scroll of improve armor", "incArmor", '?');
                                            drop->setC(attacked->col());
                                            drop->setR(attacked->row());
                                            
                                            items.push_back(drop);}
                                        if(whichS==3){
                                            GameObject* drop = new Scroll(player->row()+dr, player->col()+dc, "scroll of enhance health", "incHealth", '?');
                                            drop->setC(attacked->col());
                                            drop->setR(attacked->row());
                                            
                                            items.push_back(drop);}
                                        if(whichS==4){
                                            GameObject* drop = new Scroll(player->row()+dr, player->col()+dc, "scroll of enhance dexterity", "incDex", '?');
                                            drop->setC(attacked->col());
                                            
                                            drop->setR(attacked->row());
                                            items.push_back(drop);}
                                        if(whichS==5){
                                            
                                            GameObject* drop = new Scroll(player->row()+dr, player->col()+dc, "scroll of enhance strength", "incStr", '?');
                                            drop->setC(attacked->col());
                                            drop->setR(attacked->row());
                                          
                                            items.push_back(drop);}
                                    }
                                }
                                removeMonster(attacked); //end of monster for loop
                            }
                        }
                        else{
                            
                         
                                
                                player->move(dr, dc);
                                
                            }
                        }
                    }
                
                else{
                    
                    player->changesleep(-1);
                }
                Monster* r;
       
                for(std::list<Monster*>::iterator it = monsters.begin(); it!=monsters.end();it++){
               
           
                    
                    r = (*it);
                    int dx;
                    int dy;
                    if(r->name() == "Goblin"){
                        
                            if(r->canattack(player->row(), player->col())){
                                r->attack(player);
                            }
                            else{
                              // test the distance of the recursion( prints how long it takes to get to eachlocation 
                                                                  copyMap(map);
                                
                                Monster* x;
                                for(std::list<Monster*>::iterator it2 = monsters.begin(); it2!=monsters.end();it2++){
                                    x = (*it2);
                                    int r =x->row();
                                    int c = x->col();
                                    gamegrid[r][c] = x->symbol();
                                }
                                
                                for(int i=0; i<18 ;i++){
                                    for(int j=0; j<70;j++){
                                        stepgrid[i][j]=UNSEEN;
                                    }
                                }
                                stepgrid[r->row()][r->col()]=0;
                             
                              
                                int pC = player->col();
                                int pR = player->row();
                                iterations=0;
                                if(recursion(r->row(), r->col(), player->row(), player->col(), goblinD, stepgrid)){
                              /*   //print out num grid
                                    for(int i=0; i<18 ;i++){
                                        cout<<endl;
                                        for(int j=0; j<70;j++){
                                            if(stepgrid[i][j]== -1){
                                                cout<<'.';}
                                            else{
                                                char ch = '0'+ (char)stepgrid[i][j];
                                                cout<<(ch);
                                            }
                                   
                          
                                                                }
                                                            }*/
                                    if(stepBack(stepgrid, pR, pC)==1){
                                        find_goblin_step(stepgrid, pR, pC);
                                       
                                        r->moveS(   (  pR-(r->row() ))    , (pC-(r->col()))       );
                                                                      }
                                  
                                                                                                                    }
                                //cout<<iterations;
                                
                            }
                        
                   
                         }
                    else if(  r->cansmell(player->row(), player->col(), dy, dx, r->getSR())){
                        if(r->canattack(player->row(), player->col())){
                            r->attack(player);
                        }
                        if(dx!= 0 && dy!=0){
                            if(randInt(0,1)==1){
                                dx=0;
                            }
                            else{
                                dy=0;
                            }
                            
                        }
                        if(dy!=0 && canMove(sign(dy)+r->row(), r->col())){
                            r->moveS(sign(dy),0);
                            
                        }
                        else if(dx!=0 && canMove(r->row(), sign(dx)+r->col())){
                            r->moveS(0, sign(dx));
                        }
                        
                    }
                }
        display();
        //after all turns
        }
    }

   
    bool Game::canMove(int r, int c){
        int x,y;
        for(list<Monster*> ::iterator it= monsters.begin(); it!=monsters.end();it++){
            x = (*it)->col();
            y= (*it)->row();
            if(x==c && y==r){
                return false;
            }
        }
        if(gamegrid[r][c]=='#'){
            return false;
        }
        if(player->row() == r && player->col() == c){
            return false;
        }
        return true;
    }

Actor* Game::getMonster(int r, int c){ //only runs when there is a monster
    
   
    int mx;
    int my;
    Monster* x ;
     for(std::list<Monster*>::iterator it = monsters.begin(); it!=monsters.end();it++){
        x =(*it);
        my =x->row();
        mx =x->col();
        if(my == r && mx== c){
            return x;
            
        }
    }
    return nullptr;
}
bool Game::isWall(int r, int c){
    return (gamegrid[r][c] == '#');
}
        
bool Game::isMonster(int r, int c){
    
   
    int mx;
    int my;
    Monster* x;
    for(std::list<Monster*>::iterator it = monsters.begin(); it!=monsters.end();it++){
        x = (*it);
        my =x->row();
        mx =x->col();
        if(my == r && mx== c){
            return true;
            
        }
    }
    return false;
}
void Game::removeMonster(Actor* tbR){
    
    for(std::list<Monster*>::iterator it = monsters.begin(); it!=monsters.end();it++){
    
        if((*it)==tbR){
            monsters.erase(it);
            return;
        }
        
        }
    
   
    
    
    }

        
        
void Game::getCoordinate(int space, int& row, int& col){
    int count =0;
    
    for(int i=0; i<18;i++){
        for(int j=0; j<70;j++){
            if(gamegrid[i][j] == ' '){
                
                count++;
                if(count==space){
                    row =i;
                    col=j;
                    return;
                }
            }
        }
    }
}
int Game::countSpace(){
    int count =0;
    for(int i=0; i<18;i++){
        for(int j=0; j<70;j++){
            if(gamegrid[i][j] == ' '){
                count++;
            }
        }
    }
    return count;

}

void Game::place(Actor* actor){

    int spaces = countSpace();   //number of empty space
    int space = randInt(1,spaces); //place in map
    int placeR =0;
    int placeC =0;
    getCoordinate(space, placeR, placeC); //gets random value for coordinate;
    gamegrid[placeR][placeC]= actor->symbol();
    actor->setC(placeC);
    actor->setR(placeR);

    
}


void Game::copyMap(Map* map){
    for(int i=0; i<18;i++){
        for(int j=0; j<70;j++){
            gamegrid[i][j]=map->getGrid(i,j);
        }
    }
}
void Game::display(){
    //for all monsters in list put symbol at grid[i][j]
    //same for player and
    
    clearScreen();
    copyMap(map);
    for(size_t i =0; i<items.size();i++){
        gamegrid[items[i]->row()][items[i]->col()]=items[i]->symbol();
    }
    if(level<4){ //accounts for final level
        gamegrid[stair->row()][stair->col()]= stair->symbol();}
    if(level==4){
        gamegrid[goldenIdol->row()][goldenIdol->col()] =goldenIdol->symbol();
    }
    gamegrid[player->row()][player->col()] = player->symbol();
    Monster* x;
    for(std::list<Monster*>::iterator it = monsters.begin(); it!=monsters.end();it++){
        x = (*it);
        int r =x->row();
        int c = x->col();
        gamegrid[r][c] = x->symbol();
    }
   

    
    for(int i=0;i<18;i++){
        cout<<endl;
        
        for(int j=0; j<70; j++){
            cout<<gamegrid[i][j];
        }
    }
    cout<<endl<<"Level: " << level<< ", Hit points: " << player->health() << ", Armor: " << player->armor() << ", Strength: " << player->strength() << ", Dexterity: " << player->dexterity() <<endl;;
}







                     

// You will presumably add to this project other .h/.cpp files for the various
// classes of objects you need to play the game:  player, monsters, weapons,
// etc.  You might have a separate .h/.cpp pair for each class (e.g., Player.h,
// Bogeyman.h, etc.), or you might put the class declarations for all actors in
// Actor.h, all game objects in GameObject.h, etc.
//
// Game.h



bool Game::recursion(int cR, int cC, int tR, int tC,int goblinSmellD, int stepGrid[18][70]){
    iterations ++;
    bool reached =false;
    if(stepGrid[cR][cC]>goblinSmellD){
        return false;
    }
    if((cR==tR) && (cC==tC )) {
        return true;
    }
    
   if((stepGrid[cR][cC+1] != UNSEEN) &&((stepGrid[cR][cC+1])<(stepGrid[cR][cC]-1))){
        stepGrid[cR][cC]=stepGrid[cR][cC+1]+1;
    }
    if((stepGrid[cR][cC-1] != UNSEEN) &&((stepGrid[cR][cC-1])<(stepGrid[cR][cC]-1))){
        stepGrid[cR][cC]=stepGrid[cR][cC-1]+1;
    }
    if((stepGrid[cR+1][cC] != UNSEEN) &&((stepGrid[cR+1][cC])<(stepGrid[cR][cC]-1))){
        stepGrid[cR][cC]=stepGrid[cR+1][cC]+1;
    }
    if((stepGrid[cR-1][cC] != UNSEEN) &&((stepGrid[cR-1][cC])<(stepGrid[cR][cC]-1))){
        stepGrid[cR][cC]=stepGrid[cR-1][cC]+1;
    }
    
    
    
    if(gamegrid[cR][cC+1]==' '  && (((stepGrid[cR][cC+1])> (stepGrid[cR][cC])+1) || (stepGrid[cR][cC+1]== UNSEEN))){
        
        stepGrid[cR][cC+1]=(stepGrid[cR][cC]+1);
        if(recursion(cR,cC+1,tR,tC, goblinSmellD,stepGrid)){
            reached=true;
        }
    }
    if(gamegrid[cR][cC-1]==' '  && ((stepGrid[cR][cC-1]> stepGrid[cR][cC]+1) || (stepGrid[cR][cC-1]== UNSEEN))){
        
        stepGrid[cR][cC-1]=(stepGrid[cR][cC]+1);
        if(recursion(cR,cC-1,tR,tC, goblinSmellD,stepGrid)){
            reached=true;
        }
    }
    if(gamegrid[cR-1][cC]==' '  && ((stepGrid[cR-1][cC]> stepGrid[cR][cC]+1) || (stepGrid[cR-1][cC]== UNSEEN))){
        
        stepGrid[cR-1][cC]=(stepGrid[cR][cC]+1);
        if(recursion(cR-1,cC,tR,tC, goblinSmellD,stepGrid)){
            reached=true;
        }
    }
    if(gamegrid[cR+1][cC]==' '  && ((stepGrid[cR+1][cC]> stepGrid[cR][cC]+1) || (stepGrid[cR+1][cC]== UNSEEN))){
        
        stepGrid[cR+1][cC]=(stepGrid[cR][cC]+1);
        if(recursion(cR+1,cC,tR,tC, goblinSmellD,stepGrid)){
            reached=true;
        }
    }
   
   
    
    return reached;
}



int Game::stepBack(int numGrid[18][70], int& r, int& c){ //current r, current c of the player, find move one back
    int dr[4] ={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    int okMoves[4] = {0,0,0,0};
    int n=0;
    
    for(int i=0; i<4;i++){
        if (numGrid[r + dr[i]][c + dc[i]] == (numGrid[r][c] - 1)) { //gets all possible directions where the value is 1 less , returns a new c, r pair which shouold get you back to the goblin
            okMoves[i]=1;
            n++;
        }
        
    }
        if(n==0)
            return 0;
        //pick a random min path
        
        int okN= randInt(1,n);
        int m=0;
        for(int i=0; i<4;i++){
            m+=okMoves[i];
            if(m==okN){
                c +=dc[i];
                r+=dr[i];
                
                return 1;
                
            
        }
    }
    return 0;
}

int Game:: find_goblin_step(int numGrid[18][70],  int& pR, int& pC){
    while(numGrid[pR][pC]!=1){
        
        stepBack(numGrid, pR, pC); //gets the coordinate to within one
    }
    return 1;
}
