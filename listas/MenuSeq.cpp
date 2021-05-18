#include "MenuSeq.h"

int MenuSeq::showFirstMenu()
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

void MenuSeq::showSecondMenu()
{
    cout << "0pcoes:" <<
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

string MenuSeq::whichFile(int userOption)
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

string MenuSeq::getNewName()
{
    string newName;

    cout << "Digite o nome: ";
    cin >> newName;

    return newName;
}

int MenuSeq::getNewRg()
{
    int newRg;

    cout << "Digite o rg: ";
    cin >> newRg;

    return newRg;
}

double MenuSeq::getPosition()
{
    double position;
    cout << "Insira a posicao: ";
    cin >> position;

    return position;
}

void MenuSeq::setRemoved(string name, int rg)
{
    cout << "Nome: " << name << "  Rg: " << rg <<
    " <- Foi removido da lista" << endl << endl;
}

void MenuSeq::invalidOption()
{
    cout << "Opcao Invalida";
    exit(EXIT_FAILURE);
}

int MenuSeq::getUserOption()
{
    int userOption;
    cin >> userOption;

    return userOption;
}
