#include "Lista.h"
#include "Menu.h"
#include "leitorDeArquivos.h"

int main()
{
    Menu myMenu;
    Reader myReader;
    Lista myList;
    clock_t clockStarted, clockFinished;
    int userOption;
    double executionTime;
    int comparisons = 0, moves = 0;

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
        cout << endl << "Tempo de execucao: " << executionTime << "(seg)" << endl
        << "Comparacoes: " << comparisons << "  Atribuicoes: " << moves << endl << endl;
        comparisons = 0;
        moves = 0;
    }

    return 0;
};
