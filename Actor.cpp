//
//  Actor.cpp
//  Project 3
//
//  Created by Alexander Marcoline on 5/20/24.
//

#include "Actor.h"
#include <string>
#include "utilities.h"
#include <iostream>
#include <cmath>
using namespace std;
class Map;

//{
    
//}
Actor::Actor(int mc, int mr, char mysymbol, int hp, int armor, int strength, int dexterity, int sleep, std::string name, Weapon* weapon): mC(mc), mR(mr), mSymbol(mysymbol),mHealth(hp), mArmor(armor), mStrength(strength), mDexterity(dexterity), mSleep(sleep), mname(name), mWeapon(weapon){
    
    
}

void Actor::move(int dr, int dc){
    mR +=dr;
    mC+=dc;
    
}//moves the actor in the direction , dc and dr should both be magnitude 1 or 0
bool Actor::alive(){
    return mHealth>0;
}

GameObject* Actor:: getWeapon(){
    return mWeapon;
}
void Actor::cheat(){
    
   
    mStrength=9;
    setH(50);
}
void Player::cheatP(){
    maxH=50;
    Actor::cheat();
   
}
int Actor::col(){
    return mC;
}
int Actor::row(){
    return mR;
}
int Actor::health(){
    return mHealth;
}
int Actor::strength(){
    return mStrength;
}
int Actor::dexterity(){
    return mDexterity;}
int Actor::sleep(){
    return mSleep;
    
}
void Player::wield(int c){
    if(c>-1 && c<objInventory.size()){
        string x = objInventory[c]->name();
      
        if( (x=="scroll of improve strength") || (x=="scroll of improve health") || (x=="scroll of teleportation") || (x=="scroll of improve dexterity") || (x=="scroll of improve armor")){
            return;
        }
        setWeapon(objInventory[c]);
        cout<<"You are now wielding " << objInventory[c]->name();
    }
    
}
bool Player::isTeleportS(int c){ //function to check if target scroll in inventory is teleport, this is done for convenience in game class's play function
    if(c <0 || c>objInventory.size()-1){
        return false;
    }
    vector<GameObject*>::iterator it = objInventory.begin();
    it += c;
    string action = (*it)->action();
    return (action == "teleport");
}
void Player::readScroll(int c){ //finds the action of the scroll and applies it to the player
    if(c <0 || c> objInventory.size()-1){
        return;
    }
        vector<GameObject*>::iterator it = objInventory.begin();
        it += c;
        string action = (*it)->action();
        
        if(action == "incArmor"){
            Actor::changeArmor(randInt(1,3));
            cout<<"You read a "<< (*it)->name();
            objInventory.erase(it);
            
        }
        if(action == "incDex"){
            Actor::changeDex(1);
            cout<<"You read a "<< (*it)->name();
            objInventory.erase(it);
           
        }
        if(action == "incStr"){
            Actor::changeStrength(randInt(1,3));
            cout<<"You read a "<< (*it)->name();
            objInventory.erase(it);
            
        }
       
        if(action == "incHealth"){
            Player::changeMaxHealth(randInt(3,8));
            cout<<"You read a "<< (*it)->name();
            objInventory.erase(it);
          
        }
        if(action == "teleport"){
            cout<< "You read a " << (*it)->name();
            objInventory.erase(it);
          
        }
        
    
}
void Actor::setWeapon(GameObject* other){
    mWeapon= other;
}
void Player::changeMaxHealth(int amount){
    maxH+=amount;
}
void Player::setWeapon(GameObject* other){ //must not lose reference to other
    Actor::setWeapon(other);
}

int Actor::armor(){
    return mArmor;
}
char Actor::symbol(){
    return mSymbol;
}
void Actor::changeHealth(int amount){
    mHealth+=amount;
}
void Actor::changeDex(int amount){ //only called by player
    
    if( 99<health()+amount){
        mDexterity+=(99-mHealth);
    }
    else{
        mDexterity+=amount;
    }

}
void Actor::changeArmor(int amount){
    mArmor+=amount;
}
void Actor::changeStrength(int amount){
    mStrength+=amount;
}
void Actor::setC(int c){
    mC = c;
}
void Actor::setR(int r){
    mR = r;
}
bool Actor::drop(){
    return true;
}
bool SnakeWoman::drop(){ //odds of dropping item
    return randInt(1,3)==1;
}

std::string Actor::name(){
    return mname;
}
void Player::pickup(GameObject* weapon){ //max size of a-z, if size allows pick it up
    if(objInventory.size()>26){
        return;
    }
    objInventory.push_back(weapon);
}
void Actor::changesleep(int x){ //cant sleep for mor than 9 turns, if already sleeping and slept new sleep == max of the 2
    int temp = mSleep + x;
    if(temp>9){
        mSleep=9;
        return;
    }
    if(temp<0){
        mSleep=0;
        return;
    }
    mSleep = temp;
}


Player::Player(int mc, int mr, char mysymbol, int hp, int armor, int strength, int dexterity, int sleep, int maxh, std::string name, Weapon* weapon):Actor(mc,mr,mysymbol,hp,armor,strength, dexterity, sleep, name, weapon), maxH(maxh){
    
    objInventory.push_back(weapon);
}


void Player::inventory(){ //views inventory
    clearScreen();
    
    size_t s = objInventory.size();
    char c = 'a';
    cout<<"Inventory:"<<endl;
    for(size_t i =0; i<s; i++){
        GameObject* x = objInventory[i];
       

        cout<< c<<": " << x->name();
        cout<<endl;
        c++;
    }
}

void Player::pickUp(){
    
}
void Player::useObject(){
    
}
void Player::attack(Actor* other){ //attacks the other monster, using the given damage calcs regarding player's dex and weapon bonus, and the other's armor and dex. If appliciable, apply sleep to the monster if chance hits
   

  
    int damageDone=0;
    int damageAttack = dexterity() + objInventory[0]->dexB();
    int defense = other->armor() + other->dexterity();
    if(randInt(1, damageAttack) > randInt(1,defense)){
        damageDone = randInt(0,strength()+1 + objInventory[0]->damB());//+weaponDamage();
        if(getWeapon()->canSleep()){
            if(randInt(1,5)==1){
                int x = other->sleep();
                int y = randInt(2,6);
                
                int z = max(x,y);
                other->changesleep(z);}
        }
    }
    other->changeHealth(-(damageDone));
   // if(damageDone >0){
   //     other->seth(other->health()-damageDone);
 //   }
  
    
    
    cout<<name()<< " attacked " << other->name()<< " with " <<getWeapon()->name()<< " and dealt " << damageDone << " damage"<<endl;
        
   
}
void Actor::setH(int h){
    mHealth=h;
}
void Player::changeHealth(int amount){
    int x = amount + health();
    if(x>=maxH){
        setH(maxH);
        return;
    }
    else{
        Actor::changeHealth(amount);
    }
}



GameObject* Monster::weapon(){
    return Actor::getWeapon();
}
Monster::Monster(int mc, int mr, char mysymbol, int hp, int armor, int strength, int dexterity, int sleep,  std::string name, Weapon* weapon):Actor(mc,mr,mysymbol,hp,armor,strength, dexterity, sleep, name, weapon){}
void Monster::moveS(int pR, int pC){
 
}


void Monster::setSR(int s){
    smellR=s;
}
SnakeWoman::SnakeWoman(int mc, int mr, char mysymbol, int hp, int armor, int strength, int dexterity, int sleep, std::string name, Weapon* weapon): Monster(mc,mr,mysymbol,hp,armor,strength, dexterity, sleep, name, weapon){
    setSR(3);
}

void SnakeWoman::attack(Player* other){ //attacks using same damage calcs, but can sleep
    
    bool attacked = false;
    int damageDone = 0;
    
    int damageAttack =dexterity() + getWeapon()->dexB();
    int defense = other->armor() + other->dexterity();
    
    
    if(randInt(1, damageAttack) > randInt(1,defense)){
        damageDone = randInt(0,strength()+1 + getWeapon()->damB());//+weaponDamage();
        attacked = true;
    }
    other->Actor::changeHealth(-damageDone);
    if(attacked){
        if(randInt(1,5)==1){
            int x = other->sleep();
            int y = randInt(2,6);

            int z = max(x,y);
            other->changesleep(z);}
        
       
       
    }
 
    cout<<name()<< " attacked " << other->name()<<" with " << getWeapon()->name()<< " and dealt " << damageDone << " damage";
    cout<<endl;
}

bool Monster::drop(){
    return true;
}
void SnakeWoman::moveS(int dr, int dc){
  
            Actor::move(dr, dc);
            
        }
        //snakes have no special move function
    
int signN(int val){
    return (0<val) - (val<0);
}

int Monster::getSR(){
    return smellR;
}
//}
bool Monster::cansmell(int y1, int x1 ,int& dr, int& dc, int rad){
 //for monsters with a smell radius, caclulates if in smell radius
    int x = col();
    int y=row();
    int dx = x1-x;
    int dy = y1-y;
    dr = signN(dy);
    dc = signN(dx);
    if((abs(dx)+abs(dy))>rad ){
        return false;
    }
  
    return true;
}
bool Monster::canattack(int r1, int c1){
    int dr = r1 - row();
    int dc = c1 - col();
   
    if((dc==0 && dr==1 )||(dc==0 && dr==-1 )||(dc==1 && dr==0 )||(dc==-1 && dr==0)){
        return true;
    }
    return false;
}
    




void Monster::attack(Player* other){
    //baseline attacking function of the player
    
    bool attacked = false;
    int damageDone = 0;
    
    int damageAttack =dexterity() + getWeapon()->dexB();
    int defense = other->armor() + other->dexterity();

   

    if(randInt(1, damageAttack) > randInt(1,defense)){
        damageDone = randInt(0,strength() + getWeapon()->damB()-1);

        attacked = true;
    }
  
    other->changeHealth(-(damageDone));
    // if(damageDone >0){
    //     other->seth(other->health()-damageDone);
    //   }
    
    cout<<name()<< " attacked " << other->name() << " with a " << getWeapon()->name()<< " and dealt " << damageDone << " damage";
    cout<<endl;
    
}


Bogeyman::Bogeyman(int mc, int mr, char mysymbol, int hp, int armor, int strength, int dexterity, int sleep, std::string name, Weapon* weapon): Monster(mc,mr,mysymbol,hp,armor,strength, dexterity, sleep, name, weapon){
    setSR(5);
}

bool Bogeyman::drop(){
  
    return(randInt(1,10) == 1);
}
void Bogeyman::attack(Player* other){
    bool attacked = false;
    int damageDone = 0;
    
    int damageAttack =dexterity() + getWeapon()->dexB();
    int defense = other->armor() + other->dexterity();
    
    
    if(randInt(1, damageAttack) > randInt(1,defense)){
        damageDone = randInt(0,strength()+1 + getWeapon()->damB());
        attacked = true;
    }
    other->Actor::changeHealth(-damageDone);
   
 
    cout<<name()<< " attacked " << other->name()<<" with " << getWeapon()->name()<< " and dealt " << damageDone << " damage";
    cout<<endl;


}
void Bogeyman::moveS(int dr, int dc){ //bogeyman have no special move functio
    Actor::move(dr, dc);
}

Dragon::Dragon(int mc, int mr, char mysymbol, int hp, int armor, int strength, int dexterity, int sleep, std::string name, Weapon* weapon): Monster(mc,mr,mysymbol,hp,armor,strength, dexterity, sleep, name, weapon){
    setSR(1);

}
void Dragon::moveS(int pR, int pC){ //dragons dont move
    return;
}
void Dragon::attack(Player* other){
    bool attacked = false;
    int damageDone = 0;
    
    int damageAttack =dexterity() + getWeapon()->dexB();
    int defense = other->armor() + other->dexterity();
    
    
    if(randInt(1, damageAttack) > randInt(1,defense)){
        damageDone = randInt(0,strength()+1 + getWeapon()->damB());//+weaponDamage();
        attacked = true;
    }
    other->Actor::changeHealth(-damageDone);
   
 
    cout<<name()<< " attacked " << other->name()<<" with " << getWeapon()->name()<< " and dealt " << damageDone << " damage";
    cout<<endl;


}

bool Dragon::canmove(int x1, int y1, int& dr, int& dc){
    return false;
}
bool Dragon::drop(){
    return true;
}



Goblin::Goblin(int mc, int mr, char mysymbol, int hp, int armor, int strength, int dexterity, int sleep, std::string name,  Weapon* weapon, int smellRadius):
Monster(mc, mr, mysymbol, hp, armor, strength, dexterity, sleep, name, weapon){
smellR = smellRadius;
}
bool Goblin::drop(){
    return (randInt(1,3)==1);
}
void Goblin::attack(Player* p){
    Monster::attack(p);
}
void Goblin::moveS(int dR, int dC){
    Actor::move(dR, dC);
}

