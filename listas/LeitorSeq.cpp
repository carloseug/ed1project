#include "LeitorSeq.h"

int ReaderSeq::lineCounter (string fileName)
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
        cout << "Unable to open file" << endl;

    return counter;
}

void ReaderSeq::geradorSeq (string fileName, NodeSeq myVector[])
{
    string line, name, rgstr;
    int aux, tam, rg, i = 0;
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
        //insere no vetor
            myVector[i].name = name;
            myVector[i].rg = rg;
            i++;
            //cout << myVector[i-1].name << " " << myVector[i-1].rg << endl;
        //criterio de avaliacao

        }
        cout << "... Lista pronta";
        myFile.close();
    }

    else
        cout << "Unable to open file" << endl;
}
