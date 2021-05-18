#include "Lista.h"
#include "Menu.h"
#include "leitorDeArquivos.h"
#include "NodeSeq.h"
#include "MenuSeq.h"
#include "LeitorSeq.h"

int main()
{
    int listType;
    cout << "Escolha o tipo de lista:" << endl
         << "1. Sequencial" << endl
         << "2. Encadeada" << endl
         << "Digite sua escolha: ";
    cin >> listType;

    if(listType == 1)
    {
        MenuSeq myMenu;
        ReaderSeq myReader;
        clock_t clockStarted, clockFinished;
        int listLength, userOption;
        double executionTime;
        int comparisons = 0, moves = 0;
        string fileName;

        cout << (listLength = myReader.lineCounter(fileName = myMenu.whichFile(userOption = myMenu.showFirstMenu())))
        << " linhas nesse arquivo" << endl;

        clockStarted = clock();
        NodeSeq *myVector = (NodeSeq*) malloc (listLength * sizeof(NodeSeq));
        myReader.geradorSeq(fileName, myVector);
        clockFinished = clock();
        executionTime = (clockFinished - clockStarted) / (double)CLOCKS_PER_SEC;
        cout << endl << "Tempo gerando lista: " << executionTime << "(seg)" << endl << endl;

        if(myVector == NULL)
        {
            cout << "Erro de alocação de memoria" << endl;
            system("pause");
            exit(1);
        }

        cout << endl;

            while(userOption != 99)
        {
            myMenu.showSecondMenu();
            userOption = myMenu.getUserOption();
            switch (userOption){

            case 1:{
                string newName = myMenu.getNewName();
                int newRg = myMenu.getNewRg();
                clockStarted = clock();
                listLength += 1;

                myVector = (NodeSeq*) realloc (myVector, listLength * sizeof(NodeSeq));
                myVector[listLength-1].name = newName;
                myVector[listLength-1].rg = newRg;

                cout << endl << "Pos: "<< listLength << " Nome: "<< myVector[listLength-1].name
                << " Rg: " << myVector[listLength-1].rg << endl;

                moves += 1;

                break;
            }
            case 2:{
                string newName = myMenu.getNewName();
                int i, newRg = myMenu.getNewRg();
                clockStarted = clock();
                listLength += 1;

                myVector = (NodeSeq*) realloc (myVector, listLength * sizeof(NodeSeq));
                for(int i = listLength-1; i > 0; i--)
                {
                    myVector[i] = myVector[i-1];
                    moves += 1;
                    comparisons += 1;
                }


                myVector[0].name = newName;
                myVector[0].rg = newRg;

                cout << endl << "Pos: 1"<< " Nome: "<< myVector[0].name
                << " Rg: " << myVector[0].rg << endl;

                break;
            }
            case 3:{
                string newName = myMenu.getNewName();
                int newRg = myMenu.getNewRg();
                int posK = myMenu.getPosition();
                clockStarted = clock();
                listLength += 1;
                myVector = (NodeSeq*) realloc (myVector, listLength * sizeof(NodeSeq));

                for(int i = listLength-1; i > posK-1; i--)
                {
                    myVector[i] = myVector[i-1];
                    comparisons += 1;
                    moves += 1;
                }

                myVector[posK-1].name = newName;
                myVector[posK-1].rg = newRg;

                cout <<"Pos: " << posK << " Nome: " << myVector[posK-1].name
                << " Rg: " << myVector[posK-1].rg << endl;

                break;
            }
            case 4:{
                cout << "Removendo pos 1: " << myVector[0].name << " " << myVector[listLength-1].rg << endl;
                clockStarted = clock();
                listLength -= 1;

                for(int i = 0; i < listLength; i++)
                {
                    myVector[i] = myVector[i+1];
                    comparisons += 1;
                    moves += 1;
                }

                myVector = (NodeSeq*) realloc (myVector, listLength * sizeof(NodeSeq));

                cout << endl << "Pos 1 Atual:"<< " Nome: "<< myVector[0].name
                << " Rg: " << myVector[0].rg << " Tam Lista: "<< listLength << endl;

                break;
            }
            case 5:{
                int posK = myMenu.getPosition();
                clockStarted = clock();
                listLength -= 1;

                cout <<"Removendo pos " << posK << " Nome: " << myVector[posK-1].name
                << " Rg: " << myVector[posK-1].rg << endl;

                for(int i = posK-1; i < listLength; i++)
                {
                    myVector[i] = myVector[i+1];
                    comparisons += 1;
                    moves += 1;
                }

                myVector = (NodeSeq*) realloc (myVector, listLength * sizeof(NodeSeq));

                cout <<"Pos " << posK << " atual >> Nome: " << myVector[posK-1].name
                << " Rg: " << myVector[posK-1].rg << endl;

                break;
            }
            case 6:{
                clockStarted = clock();
                listLength -= 1;

                cout <<"Removendo pos " << listLength+1 << ">> Nome: " << myVector[listLength].name
                << " Rg: " << myVector[listLength].rg << endl;

                myVector = (NodeSeq*) realloc (myVector, listLength * sizeof(NodeSeq));
                moves += 1;

                cout <<"Pos " << listLength << " atual >> Nome: " << myVector[listLength-1].name
                << " Rg: " << myVector[listLength-1].rg << endl;

                break;
            }
            case 7:{
                int i, aux = 0, searchRg = myMenu.getNewRg();
                clockStarted = clock();

                i = myVector[aux].rg;

                while(i != searchRg)
                {
                    aux++;
                    i = myVector[aux].rg;
                    comparisons += 1;
                }

                cout << "Pos: " << aux+1 << " Nome: " << myVector[aux].name << " Rg: " << myVector[aux].rg << endl;

                break;

            }
            case 8:{
                clockStarted = clock();
                for(int i = 0; i < listLength; i++)
                {
                    cout << i+1 << " " << myVector[i].name << " " << myVector[i].rg << endl;
                    comparisons += 1;
                }

                break;
            }
            case 9:{
                clockStarted = clock();
                ofstream savingFile ("NomeRGSave.txt");

                if (savingFile.is_open())
                {
                    for (int i = 0; i < listLength; i++){
                        savingFile << myVector[i].name << "," << myVector[i].rg << endl;
                        comparisons += 1;
                        moves += 1;
                        }

                    savingFile.close();
                    cout << "Arquivo salvo com sucesso!" << endl;
                }
                else cout << "Unable to open file";
                break;
            }
            case 10:{
                free(myVector);
                exit (0);
            }
            default:{
                cout << endl << "-> Opçao invalida" << endl;
                break;
            }
        }
            clockFinished = clock();
            executionTime = (clockFinished - clockStarted) / (double)CLOCKS_PER_SEC;
            cout << endl << "Tempo de execucao: " << executionTime << "(seg)" << endl
            << "Comparacoes: " << comparisons << "  Atribuicoes: " << moves << endl << endl;
            comparisons = 0;
            moves = 0;

        }

        free(myVector);
    }

    else if(listType == 2)
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
    }

    else
    {
        cout << "Opcao invalida!" << endl;
        main();
    }

    return 0;
};
