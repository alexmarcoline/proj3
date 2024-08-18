//
//  Map.hpp
//  Project 3
//
//  Created by Alexander Marcoline on 5/20/24.
//

#ifndef Map_hpp
#define Map_hpp
#include <list>
#include <vector>
#include "Actor.h"

class Map{
   
public:
    Map();
    
    void initialize();
    int level();
    void display();
    void createRooms();
    void setLevel();
    void clear();
    void setGrid(int x, int y, char sym);
    char getGrid(int row, int col );
  
    

private:
    int mlevel;
    char grid[18][70];

  

    
    
    
};
#endif /* Map_hpp */
