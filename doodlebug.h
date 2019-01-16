#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include <iostream>
#include "grid.h"
#include "organism.h"

class Doodlebug : public Organism{
public:
    
    Doodlebug(Grid* theGrid, int xc, int yc);
    void move();
    void breed();
    bool getType() const;
    char theOrg() const;
    int size() const;
    bool isDead() const;  
    bool onGrid(int checkX, int checkY);
    
private:
    
    void offSpring(int newX, int newY);
    int stepsToDie;
};

#endif