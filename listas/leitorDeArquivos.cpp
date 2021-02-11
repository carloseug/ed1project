#include "leitorDeArquivos.h"

int Reader::lineCounter(string fileName)
{
    int counter = 0;
    string line;
    ifstream myFile (fileName);

    if (myFile.is_open())
    {
        while (getline (myFile,line))
        {
            counter++;
        }
        myFile.close();
    }

    else
        cout << "Falha ao abrir arquivo" << endl;

    return counter;
}

void Reader::geradorEncadeada(string fileName, Lista* myList)
{
    string line;
    string name, rgstr;
    int aux, tam, rg;
    ifstream myFile (fileName);

    if (myFile.is_open())
    {
        while (getline (myFile, line))
        {
        //cria as strings name e rg
            aux = line.find(",");
            name = line.substr(0, aux);
            rgstr = line.substr(aux+1);

        //converte a string rg em int
            tam = rgstr.length();
            char rgvector[tam + 1];
            rgstr.copy(rgvector, tam, 0);
            rgvector[tam] = 0;
            rg = atoi(rgvector);

        //gera os nos
            myList->insertNode(new Node(name, rg));

        }

        myFile.close();
    }

    else
        cout << "Unable to open file" << endl;
}
