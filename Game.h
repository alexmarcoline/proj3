
#ifndef GAME_H
#define GAME_H
#include "Map.h"
#include "GameObject.h"
#include <list>
// You may add data members and other member functions to this class.

class Game
{
    

public:
    Game(int goblinSmellDistance);
    ~Game();
    void play();
    void getCoordinate(int space, int& row, int& col);
    int countSpace();
    void copyMap(Map* map);
    void display();
    void place(Actor* actor);
    bool isWall(int r, int c);
    bool isMonster(int r, int c);
    bool isObj(int r, int c);
    Actor* getMonster(int r, int c);
    void removeMonster(Actor* tbR);
    bool canMove(int r, int c);
    void newLevel(int level);
    void teleportScroll(Player* p, int blankSpace);
    void placeMonsters(int level);
    void placeObjects();
    bool pathExists( int sr, int sc, int er, int ec);
  
    int stepBack(int numGrid[18][70], int& cr, int& cC);
    int find_goblin_step(int numGrid[18][70], int& pR, int& pC);
    bool recursion(int cC, int cR, int tC, int tR, int goblinSmellD, int stepGrid[18][70]);
private:
    Map* map;
    Player* player;
    std::list<Monster*> monsters;
    std::vector<GameObject*> items;
    char gamegrid[18][70];
    int goblinDistance;
    GameObject* stair;
    GameObject* goldenIdol;
    int level;
    int goblinD;
    int stepgrid[18][70];
};

#endif // GAME_INCLUDED
