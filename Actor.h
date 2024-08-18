//
//  Actor.hpp
//  Project 3
//
//  Created by Alexander Marcoline on 5/20/24.
//

#ifndef ACTOR_H
#define ACTOR_H
#include <string>
#include <vector>

#include "GameObject.h"
#include "GameObject.h"


class Actor{
   
public:
    //Actor(int mc, int mr, int marmor, int mstrength, int health, int mdexterity,int msleep, char mysymbol, Map* map);
   // Actor(int mc, int mr, char mysymbol, Map* map);
    Actor(int mc, int mr, char mysymbol, int hp, int armor, int strength, int dexterity, int sleep, std::string name, Weapon* weapon);
   // virtual ~Actor();
  virtual void move(int dr, int dc);
    void cheat();
    bool alive();
    int health();
    int armor();
    int strength();
    int dexterity();
    int sleep();
    void changesleep(int x);
    int col();
    int row();
    char symbol();
    void setC(int c);
    void setR(int r);
    void setH(int h);
    virtual bool drop();
    void setWeapon(GameObject* other);
  virtual void changeHealth(int amount);//im[
    void changeArmor(int amount);
    void changeDex(int amount);
    void changeStrength(int amount);
    std::string name();
    GameObject* getWeapon();
    
private:
    char mSymbol;
    int mC;
    int mR;
    int mHealth;
    int mArmor;
    int mStrength;
    int mDexterity;
    int mSleep;
    GameObject* mWeapon;
    std::string mname;
    
  //weapons
};


class Player: public Actor{
   
public:
    Player(int mc, int mr, char mysymbol, int hp, int armor, int strength, int dexterity, int sleep, int maxh , std::string name, Weapon* weapon);
    void attack(Actor* other);
    void useObject();//imp
    void inventory();//imp
    void pickUp();//imp
    void changeHealth(int amount);
    void pickup(GameObject* weapon);
    void viewInventory();
    void wield(int c);
    void readScroll(int c);
    void setWeapon(GameObject* other);
    void changeMaxHealth(int amount);
    bool isTeleportS(int c);
    void cheatP();
private:
    int maxH = 20;
    std::vector<GameObject*> objInventory;
    
    //queue of items for inventory
};



class Monster:public Actor{
public:
    Monster(int mc, int mr, char mysymbol, int hp, int armor, int strength, int dexterity, int sleep, std::string name, Weapon* weapon);
    bool canattack(int r1, int c1);
    virtual void moveS(int pR, int pC);
    virtual void attack(Player* other);
    GameObject* weapon();
    bool cansmell(int y1, int x1 ,int& dr, int& dc, int rad);
    virtual bool drop();
    void setSR(int s);
    int getSR();
private:
    Weapon* mweapon;//for now;
    std::string mname;
    int smellR;
};
    

class SnakeWoman:public Monster{
public:
    SnakeWoman(int mc, int mr, char mysymbol, int hp, int armor, int strength, int dexterity, int sleep, std::string name,  Weapon* weapon);
    void moveS(int pR, int pC);
    void attack(Player* other);
    bool canmove(int x1, int y1, int & dr, int& dc);
    bool drop();
  
    
};
    
class Bogeyman : public Monster{
public:
    Bogeyman(int mc, int mr, char mysymbol, int hp, int armor, int strength, int dexterity, int sleep, std::string name,  Weapon* weapon);
    void moveS(int pR, int pC);
    void attack(Player* other);
    bool canmove(int x1, int y1, int& dr, int& dc);
    bool drop();

};
class Dragon : public Monster{
public:
    Dragon(int mc, int mr, char mysymbol, int hp, int armor, int strength, int dexterity, int sleep, std::string name,  Weapon* weapon);
    void moveS(int pR, int pC);
    void attack(Player* other);
    bool canmove(int x1, int y1, int& dr, int& dc);
    bool drop();

};


class Goblin: public Monster{
public:
    Goblin(int mc, int mr, char mysymbol, int hp, int armor, int strength, int dexterity, int sleep, std::string name,  Weapon* weapon, int smellRadius);
    
    bool drop();
    void attack(Player* p);
    void moveS(int dR, int dC);
private:
    int smellR;
};
//
#endif /* Actor_hpp */
