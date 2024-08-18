//
//  GameObject.hpp
//  Project 3
//
//  Created by Alexander Marcoline on 5/21/24.
//

#ifndef GameObject_hpp
#define GameObject_hpp
#include <string>

class GameObject{
public:
    GameObject(int x, int y, std::string name, std::string action, char symbol );
   virtual void effect();
    virtual int dexB();
    virtual int damB();
    int row();
    char symbol();
    int col();
    void setR(int r);
    void setC(int c);
    std::string name();
    std::string action();
    void setS(char c);
    virtual bool canSleep();
private:
    char msymbol;
    std::string mname;
    std::string maction;
    int mR;
    int mC;
    std::string type;
};


class Weapon:public GameObject{
public:
    Weapon(int x, int y, std::string name, std::string action, int dexterityB, int damageB, bool canSleep, char symbol);
    int dexB();
    int damB();
    bool canSleep();
private:
    int dexBonus;
    int damageAm;
    bool cansleep;
};


class Scroll:public GameObject{
public:
    Scroll(int x, int y, std::string name, std::string action, char symbol): GameObject(x,y,name,action, symbol){}
    
};
#endif /* GameObject_hpp */
