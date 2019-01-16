
#ifndef ORGANISM_H
#define ORGANISM_H
#include "grid.h"

//abstract class - pure virtual functions
class Grid;
class Organism{
    public:
        Organism(Grid* theGrid, int xc, int yc); //constructor

        virtual void move() = 0;
        virtual void breed() = 0;
        void setMove(bool checkMove); //sets move
        bool checkMove() const; //checks move
        virtual char theOrg() const = 0; // The character (X or O)
        virtual bool getType() const = 0; //true if ant
        virtual bool isDead() const; //true if dead
        bool onGrid(int checkX, int checkY); //true if on grid
        virtual void offSpring(int offX, int offY) = 0;
        void moveTo(int newX, int newY);//moves to (xNew, yNew)
        void breedHere();//breeds in adjacent cell
        int x;
        int y;
        int stepsToBreed;
        bool moved;
        Grid* grid;

        virtual ~Organism() { } //destructor

        
};

#endif 