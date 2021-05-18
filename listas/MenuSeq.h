#ifndef MENUSEQ_H
#define MENUSEQ_H
#include "NodeSeq.h"

class MenuSeq{
    public:

    int showFirstMenu();
    void showSecondMenu();
    string whichFile(int userOption);
    string getNewName();
    int getNewRg();
    double getPosition();
    void setRemoved(string name, int rg);
    void invalidOption();
    int getUserOption();

};

#endif // MENUSEQ_H
