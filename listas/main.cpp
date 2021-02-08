#include "Lista.h"
#include "Menu.cpp"
#include "leitorDeArquivos.cpp"

int main()
{
    Menu myMenu;
    Reader myReader;
    Lista myList;
    int userOption;

    cout << myReader.lineCounter(myMenu.whichFile(userOption = myMenu.showFirstMenu()))
    << " linhas nesse arquivo" << endl << endl;
    myReader.geradorEncadeada(myMenu.whichFile(userOption), &myList);


    while(userOption != 99)
    {
        double c, m;
        myMenu.showSecondMenu();
        myMenu.loopingMenu(userOption = myMenu.getUserOption(), &myList, &c, &m);

    }

    return 0;
};
