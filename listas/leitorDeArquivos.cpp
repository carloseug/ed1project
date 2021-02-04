#ifndef LEITORDEARQUIVOS_CPP
#define LEITORDEARQUIVOS_CPP
#include "Lista.h"

using namespace std;

class Reader{
public:

    int lineCounter(string fileName)
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

    void geradorEncadeada(string fileName, Lista* myList, double* c, double* m)
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

            //gera os nós
                myList->insertNode(new Node(name, rg));

            //criterio de avaliacao
                *m = *m + 2;

            }
            *m = *m + 2;
            *c = *c + 1;

            myFile.close();
        }

        else
            cout << "Unable to open file" << endl;
    }

/*    void geradorSeq(string fileName, NodeSeq *listaSeq, double* c, double* m)
    {
        string line, name, rgstr;
        int aux, tam, rg;
        long unsigned int i = 0;
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
                listaSeq[i].rg  = rg;
                listaSeq[i].name  = name;
                listaSeq[i].position  = i + 1;
                i++;

            //criterio de avaliacao

            }
            cout << "... Lista pronta";
            myFile.close();

        }

        else
            cout << "Unable to open file" << endl;
    }*/
};

#endif // LEITORDEARQUIVOS_CPP
