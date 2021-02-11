#ifndef MENU_CPP
#define MENU_CPP
#include "Lista.h"

using namespace std;

class Menu{
    public:
    clock_t clockStarted, clockFinished;

    int chooseListType()
    {
        cout << " > Escolha o tipo de lista <" <<
        endl << "1 - Lista Sequencial" <<
        endl << "2 - Lista Encadeada" <<
        endl << "Sua escolha: ";

        int listType;
        cin >> listType;

        if(listType > 2 || listType < 1)
            invalidOption();
        else
            return listType;
    }

    int showFirstMenu()
    {
        cout << "1 - 10 itens" <<
        endl << "2 - 50 itens" <<
        endl << "3 - 100 itens" <<
        endl << "4 - 1K itens" <<
        endl << "5 - 10K itens" <<
        endl << "6 - 1M itens" <<
        endl << "7 - 10M itens" <<
        endl << "8 - Ultimo save" <<
        endl << "> Escolha o arquivo: ";

        int listLength;
        cin >> listLength;

        if(listLength > 0 && listLength < 9)
            return listLength;
        else
            invalidOption();
    }

    void showSecondMenu()
    {
        cout << "Opcoes:" <<
        endl << "1 - Inserir usuario no fim da lista" <<
        endl << "2 - Inserir usuario no inicio da lista" <<
        endl << "3 - Inserir usuario numa posicao K da lista" <<
        endl << "4 - Remover o Primeiro usuario" <<
        endl << "5 - Remover um usuario K" <<
        endl << "6 - Remover o Ultimo usuario" <<
        endl << "7 - Buscar na Lista" <<
        endl << "8 - Mostrar a lista" <<
        endl << "9 - Salvar (arquivo separado)" <<
        endl << "10 - Sair" << endl <<
        endl << "Escolha uma das opcoes acima: ";
    }

    string whichFile(int userOption)
    {
        string fileName;
        switch (userOption){
            case 1:{
                fileName = "NomeRG10.txt";
                break;
                }
            case 2:{
                fileName = "NomeRG50.txt";
                break;
                }
            case 3:{
                fileName = "NomeRG100.txt";
                break;
                }
            case 4:{
                fileName = "NomeRG1K.txt";
                break;
                }
            case 5:{
                fileName = "NomeRG10K.txt";
                break;
            }
            case 6:{
                fileName = "NomeRG1M.txt";
                break;
            }
            case 7:{
                fileName = "NomeRG10M.txt";
                break;
            }
            case 8:{
                fileName = "NomeRGSave.txt";
                break;
            }
            default:{
                cout << endl << "OPCAO INVALIDA" << endl << endl;
                return 0;
            }
        }

        return fileName;
    }

    string getNewName()
    {
        string newName;

        cout << "Digite o nome: ";
        cin >> newName;

        return newName;
    }

    int getNewRg()
    {
        int newRg;

        cout << "Digite o rg: ";
        cin >> newRg;

        return newRg;
    }

    double getPosition()
    {
        double position;
        cout << "Insira a posicao: ";
        cin >> position;

        return position;
    }

    void setRemoved(string name, int rg)
    {
        cout << "Nome: " << name << "  Rg: " << rg <<
        " <- Foi removido da lista" << endl << endl;
    }

    void loopingMenu(int userOption, Lista* myList, double* c, double* m,
                     clock_t initial_time, clock_t final_time, double* executionTime)
    {
        switch (userOption){

            case 1:{
                string newName = getNewName();
                int newRg = getNewRg();

                myList->insertNode (new Node (newName, newRg));
                myList->updatePositions();
                myList->showInfo(myList->listLength());
                *m += 2;

                break;
            }
            case 2:{
                string newName = getNewName();
                int newRg = getNewRg();

                myList->insertFirstNode (new Node (newName, newRg));
                myList->updatePositions();
                myList->showInfo(1);
                *m += 2;

                break;
            }
            case 3:{
                string newName = getNewName();
                int newRg = getNewRg();

                double i, positionK = getPosition();

                Node* Aux = myList->pointerToFirst;
                *m = *m + 1;

                for (i = 2; i < positionK; i++){
                    Aux = Aux->next;
                    *c = *c + 1;
                    *m = *m + 1;
                }

                myList->insertMidNode (Aux, new Node (newName, newRg));
                *m = *m + 2;
                myList->updatePositions();
                myList->showInfo(positionK);

                break;
            }
            case 4:{
                setRemoved(myList->pointerToFirst->name, myList->pointerToFirst->rg);
                myList->removeFirstNode();
                *m+=2;
                myList->updatePositions();

                break;
            }
            case 5:{
                double userBeingRemoved = getPosition();
                cout << endl << "-> Removendo da lista: ";

                myList->showInfo(userBeingRemoved);
                myList->removeMidNode(userBeingRemoved - 1);
                *c += userBeingRemoved -1;
                *m += 2;
                myList->updatePositions();

                break;
            }
            case 6:{
                cout << endl << "-> Removendo da lista:";

                myList->showInfo(myList->listLength());
                myList->removeLastNode();
                *c = myList->listLength() - 1;
                *m = (myList->listLength() - 1) + 3;
                break;
            }
            case 7:{
                int searchRg = getNewRg();
                Node* aux = myList->pointerToFirst;
                *m = *m + 1;

                while (aux->rg != searchRg)
                {
                    *c = *c + 1;
                    aux = aux->next;
                    *m = *m + 1;
                }
                *c = *c + 1;
                myList->showInfo(aux->position);

                break;

            }
            case 8:{
                myList->showListInfo();
                *m = *m + 1;
                *c = *c + myList->listLength() + 1;

                break;
            }
            case 9:{
                myList->saveList();
                *c = myList->listLength() + 1;
                *m = myList->listLength();

                break;
            }
            case 10:{
                exit (0);
            }
            default:{
                cout << endl << "-> Opcao invalida" << endl;
                break;
            }
        }

    }

    void invalidOption()
    {
        cout << "Opcao Invalida";
        exit(EXIT_FAILURE);
    }

    int getUserOption()
    {
        int userOption;
        cin >> userOption;

        return userOption;
    }
};

#endif // MENU_CPP
