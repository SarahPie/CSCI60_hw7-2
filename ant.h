#ifndef ANT_H
#define ANT_H

#include <iostream>
#include "organism.h"
#include "grid.h"

class Ant : public Organism{
public:
    Ant(Grid* theGrid, int xc, int yc);
    void move();
    void breed();  
    bool getType() const;  
    char theOrg() const;
    bool onGrid(int checkX, int checkY);
    
private:
    void offSpring(int offX, int offY);
};

#endif