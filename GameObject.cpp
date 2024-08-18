//
//  GameObject.cpp
//  Project 3
//
//  Created by Alexander Marcoline on 5/21/24.
//
#include <iostream>
#include "GameObject.h"
GameObject::GameObject(int x, int y, std::string name, std::string action, char symbol):mC(x), mR(y), mname(name), maction(action), msymbol(symbol)
{
}
void GameObject::effect(){
    std::cout<<"effect";
}
std::string GameObject::name(){
    return mname;
}
std::string GameObject::action(){
    return maction;
}
Weapon::Weapon(int x, int y, std::string name, std::string action, int dexterityB, int damageB, bool canSleep, char symbol): GameObject(x,y,name,action, symbol), dexBonus(dexterityB), damageAm(damageB), cansleep(canSleep){
    
}
int GameObject::damB(){
    return 1;
}
int GameObject::dexB(){
    return 1;
}
int Weapon:: damB(){
    return damageAm;
    
}
int Weapon::dexB(){
    return dexBonus;
}
int GameObject::col(){
    return mC;
}
int GameObject::row(){
    return mR;
}
char GameObject::symbol(){
    return msymbol;
}
void GameObject::setC(int c){
    mC=c;
}
void GameObject::setR(int r){
    mR=r;
}
void GameObject::setS(char c){
    msymbol=c;
}
bool Weapon::canSleep(){
    return cansleep;
}
bool GameObject::canSleep(){
    return false;
}
