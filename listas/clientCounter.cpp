#include "Lista.h"
#include "Menu.cpp"
#include "leitorDeArquivos.cpp"

class clientCounter{
    public:

    void startEncadeada()
    {
        //Instacia Objetos
        Lista myList;
        Menu myMenu;
        Reader myReader;

        //Variaveis locais uteis
        int userOption, listLength;
        double compNum, atribNum;
        string fileName;

        //Funcao cronometro
        clock_t start_t, end_t, total_t;

        //Chama o tipo de lista
        userOption = myMenu.showFirstMenu();

        //Preenche fileName com nome do arquivo escolhido
        fileName = myMenu.whichFile(userOption);
        //Preenche listLength com o tamanho (em linhas) da lista
        listLength = myReader.lineCounter(fileName);
        //Lê o arquivo e instacia a lista
        myReader.geradorEncadeada(fileName, &myList, &compNum, &atribNum);
        //Coloca indice nos itens da lista
        myList.updatePositions();

        //imprime as movimentações
        cout << endl << "C: " << fixed << setprecision(0) << compNum
        << " - M: " << fixed << setprecision(0) << atribNum << endl << endl;

        char loop = 'x';
        while (loop != 'y')
        {
            compNum = 0;
            atribNum = 0;

            myMenu.showSecondMenu();
            cin >> userOption;
            start_t = clock();

            //Executa função escolhida
            myMenu.loopingMenu(userOption, &myList, &compNum, &atribNum);

            end_t = clock ();
            total_t = (double) ((end_t - start_t) / CLOCKS_PER_SEC);
            cout << "C: " << fixed << setprecision(0) << compNum << " - M: " << fixed << setprecision(0) << atribNum << endl
             << "Tempo de execução: " << fixed << setprecision(20) << (double) total_t << endl << endl;
        }

    }

    void startSequencial()
    {
        //Instacia os objetos
        Menu myMenu;
        Reader myReader;

        //Variaveis locais
        int userOption;
        double compNum, atribNum;
        long unsigned int listLength;
        string fileName;
        clock_t start_t, end_t, total_t;

        //Escolhe o arquivo
        userOption = myMenu.showFirstMenu();
        fileName = myMenu.whichFile(userOption);

        //Conhece o tamanho
        listLength = myReader.lineCounter(fileName);
        cout << "...Carregando "<< listLength << " nós" << endl;
        NodeSeq *listaSeq = (NodeSeq*) calloc (listLength, sizeof(NodeSeq));
        cout << "...Alocando memória" << endl;

        //Cria a lista
        myReader.geradorSeq(fileName, listaSeq, &compNum, &atribNum);

        cout << endl << "C: " << fixed << setprecision(0) << compNum
        << " - M: " << fixed << setprecision(0) << atribNum << endl << endl;

        //Entra em loop forçado pra aparecer as opções
        char loop = 'x';
        while (loop != 'y')
        {
            compNum = 0;
            atribNum = 0;

            myMenu.showSecondMenu();
            cin >> userOption;
            start_t = clock ();

            myMenu.loopingMenuSeq(userOption, listaSeq, &listLength, &compNum, &atribNum);

            end_t = clock ();
            total_t = (double) ((end_t - start_t) / CLOCKS_PER_SEC);
            cout << endl << "C: " << fixed << setprecision(0) << compNum << " - M: " << fixed << setprecision(0) << atribNum << endl
             << "Tempo de execução: " << fixed << setprecision(20) << (double) total_t << endl << endl;
        }

        free(listaSeq);

    }
};
