#ifndef MENU_H
#define MENU_H

#include "Lista.h"

class Menu{
public:

    clock_t clockStarted, clockFinished;

    int chooseListType();
    int showFirstMenu();
    void showSecondMenu();
    string whichFile(int userOption);
    string getNewName();
    int getNewRg();
    double getPosition();
    void setRemoved(string name, int rg);
    void loopingMenu(int userOption, Lista* myList, int* c, int* m,
                     clock_t initial_time, clock_t final_time, double* executionTime);
    void invalidOption();
    int getUserOption();

};

#endif // MENU_H
