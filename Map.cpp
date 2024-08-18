//
//  Map.cpp
//  Project 3
//
//  Created by Alexander Marcoline on 5/20/24.
//

#include "Map.h"
#include "Actor.h"
#include <iostream>
#include "utilities.h"
#include <string>
using namespace std;

Map::Map(){
   
  
   
    mlevel=0;
    list<Actor*> mQueue;
    
    for(int i=0;i<18;i++){
        for(int j=0;j<70;j++){
            grid[i][j]='#';
        }
    }
}

void Map::initialize(){
   
    createRooms();
 
   
    
    clearScreen();
    
    
    
    
    
 
    
    
    
}


void Map::display(){
    for(int i=0;i<18;i++){
        cout<<endl;
        for(int j=0;j<70;j++){
            cout<<grid[i][j];
        }
    }

}
int Map::level(){
    return mlevel;
}

void Map::createRooms(){
    
    
    
    
    
    int dividerxR = randInt(45,55);
    int dividerxL = randInt(20, 24);
    int dividerY = randInt(5,9);
    
    
    int y1 = randInt(1,4);
    int y2 = randInt(dividerY+2,12);
    int y3 = randInt(1, 4);
    int y4 = randInt(dividerY+3,12);
    int y5 = randInt(1, 4);
    int y6 = randInt(dividerY+1,12);
    
    int x1 = randInt (1,6);
    int x2 = randInt (dividerxL+1,dividerxL+10);
    int x3 = randInt (dividerxR+2,65);
    int x4 = randInt (1,6);
    int x5 = randInt (dividerxL+1,dividerxL+10);
    int x6 = randInt (dividerxR,60);
    
    int rx1 = randInt(64,68);
    int rx2 = randInt(64,66);
    int ry2 = randInt(15,16);
    int ry1 = randInt(15,16);
    int ry3 = randInt(15,16);
    
    
    
    
    
    
    
    for(int i=x1; i<dividerxL;i++){
        for(int j=y1;j<dividerY;j++){
            grid[j][i]=' ';
        }
    }
    for(int i=x2; i<dividerxR ;i++){
        for(int j=y3;j<dividerY;j++){
            grid[j][i]=' ';
        }
    }
    for(int i=x3; i<rx1 ;i++){
        for(int j=y5;j<dividerY;j++){
            grid[j][i]=' ';
        }
    }
    
    for(int i=x4; i<dividerxL;i++){
        for(int j=y2;j<ry1;j++){
            grid[j][i]=' ';
        }
    }
    for(int i=x5; i<dividerxR;i++){
        for(int j=y4;j<ry2;j++){
            grid[j][i]=' ';
        }
    }
    for(int i=x6; i<rx2;i++){
        for(int j=y6;j<ry3;j++){
            grid[j][i]=' ';
        }
    }
    
    
    
    //tunnel making
    int i=x1,j=y1;
    while(i!=x2){
        if(i<=x2){
            grid[j][i]=' ';
            i++;
        }
        
    }
    while(j!=y3){
        if(j<y3){
            grid[j][i]=' ';
            j++;
        }
        else if (j>y3){
            grid[j][i]=' ';
            j--;
        }
    }
    i=x2;
    j=y3;
    while(i!=x3){
        if(i<=x3){
            grid[j][i]=' ';
            i++;
        }
        
    }
    while(j!=y5){
        if(j<y5){
            grid[j][i]=' ';
            j++;
        }
        else if (j>y5){
            grid[j][i]=' ';
            j--;
        }
    }
    int a = x1;
    int b = y1;
    while(b!=y2){
        grid[b][a]=' ';
        b++;
    }
    if(a<=x4){
        while(a!=x4){
            grid[b][a]=' ';
            a++;
        }
    }
    else if(a>x4){
        while(a!=x4){
            grid[b][a]=' ';
            a--;
        }
    }
    
    a=x4;
    b=y2;
    while(a<=x5){
        grid[b][a]=' ';
        a++;
    }
    while(b!=y4){
        if(b>y4){
            grid[b][a]=' ';
            b--;
        }
        else{
            grid[b][a]=' ';
            b++;
        }
    }
    
    
    a=x5;
    b=y4;
    while(a<=x6){
        grid[b][a]=' ';
        a++;
    }
    
    while(b!=y6){
        if(b>y6){
            grid[b][a]=' ';
            b--;
        }
        else{
            grid[b][a]=' ';
            b++;
            
        }
    }
}
   
    
 
char Map::getGrid(int row, int col){
    return grid[row][col];
}
void Map::clear(){
    for(int i=0; i<18; i++){
        for(int j=0; j<70;j++){
            grid[i][j]='#';
        }
    }
}
