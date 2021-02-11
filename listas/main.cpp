#include "Lista.h"
#include "Menu.cpp"
#include "leitorDeArquivos.cpp"

int main()
{
    Menu myMenu;
    Reader myReader;
    Lista myList;
    clock_t clockStarted, clockFinished;
    int userOption;
    double comparisons, moves, executionTime;

    cout << myReader.lineCounter(myMenu.whichFile(userOption = myMenu.showFirstMenu()))
    << " linhas nesse arquivo" << endl;
    clockStarted = clock();
    myReader.geradorEncadeada(myMenu.whichFile(userOption), &myList);
    clockFinished = clock();
    executionTime = (clockFinished - clockStarted) / (double)CLOCKS_PER_SEC;
    cout << "Tempo gerando lista: " << executionTime << "(seg)" << endl << endl;
    myList.updatePositions();

    while(userOption != 99)
    {
        myMenu.showSecondMenu();
        myMenu.loopingMenu(userOption = myMenu.getUserOption(), &myList,
                           &comparisons, &moves, clockStarted, clockFinished, &executionTime);

    }

    return 0;
};
