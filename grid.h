#ifndef GRID_H
#define GRID_H
#include "organism.h"

const int SIZE = 20; //20*20 grid

const int ANTS = 100; //starting # of ants
const int DBUGS = 5; //starting # of doodlebugs

const int ABREED = 3; //time steps to breed 
const int DBREED = 8; //time steps to breed 

const int BUGDIES = 3; //time steps to doodlebug death

struct coords{
    int x;
    int y;
};

class Organism;
class Grid{
    public:
        Grid(unsigned int randomSpot); //constructor
        
        Organism* start(int x, int y) const; //starting coord (x,y)
        void nextMove(int x, int y, Organism* org);// next coord(x,y).
        void userScreen() const;
        void step(); //time step
        coords randomCoords() const;//returns random coord in the grid
        int randomDirection() const;//returns random up, down, etc.
        void makeOrg(bool orgType, int count);
        void resetOrgs();
        void moveOrgs(bool theType);
        void clean(); //removes dead orgs
        void breedOrgs();

        ~Grid(); //destructor

    private:
        Organism* gameGrid[SIZE][SIZE];
};

#endif 