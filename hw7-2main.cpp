#include <iostream>
#include <ctime>   
#include "grid.h"
using namespace std;

int main(){

    int step;

    cout << endl;
    cout << "Welcome to the harsh world of doodlebugs and ants!" << endl;
    cout << "THE BEGINNING: ";

    Grid aGame(time(0));
    aGame.userScreen();

    cout << endl;
    cout << "Press 'q' to exit the game." << endl;
    cout << "Press 'Enter' begin the Ant-Doodlebug duel to the death!: ";
    
    //may need to press 'Enter' twice sometimes
    do{
        cin.get();
        aGame.step();
        aGame.userScreen();
    }
    while(cin.get()== '\n');

    cout << "Hope you enjoyed the game!" << endl;

    return 0;
}