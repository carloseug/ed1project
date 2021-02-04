#include "Lista.h"

    void Lista::insertFirstNode (Node* newFirstNode)
    {
        newFirstNode->next = pointerToFirst;
        pointerToFirst = newFirstNode;
    }

    void Lista::insertNode (Node* newNode)
    {
        if (pointerToFirst == NULL)
        {
            pointerToFirst = newNode;
            pointerToLast = newNode;
        }

        else
        {
            pointerToLast->next = newNode;
            pointerToLast = newNode;
        }
    }

    void Lista::insertMidNode (Node* previousNode, Node* newNode)
    {
        newNode->next = previousNode->next;
        previousNode->next = newNode;
    }

    void Lista::showInfo (int userPosition)
    {
        Node* aux = pointerToFirst;

        while (aux->position != userPosition)
        {
            aux = aux->next;
        }

        cout << endl << "Posicao: " << aux->position << "  Nome: " << aux->name << "  Rg: " << aux->rg << endl << endl;
    }

    void Lista::showListInfo ()
    {
        if (pointerToFirst == NULL)
            cout << "Lista vazia" << endl;

        else if (pointerToFirst == pointerToLast)
            cout << "Unico item: " << pointerToFirst->name << ", " << pointerToFirst->rg << endl;

        else
        {
            Node* List = pointerToFirst;
            cout << endl << "> Lista  (Posicao/Nome/RG):" << endl;

            while (List != NULL)
            {
                cout << List->position << "- "<<List->name << ", " << List->rg << endl;
                List = List->next;
            }

            cout << endl;
        }
    }

    void Lista::removeFirstNode ()
    {
        Node* aux = pointerToFirst;
        pointerToFirst = pointerToFirst->next;
        delete aux;
    }

    void Lista::removeMidNode (int positionK)
    {
        Node* aux = pointerToFirst;

        while (aux->position < positionK)
        {
            aux = aux->next;
        }

        aux->next = aux->next->next;
    }

    void Lista::removeLastNode ()
    {
        Node* aux = pointerToFirst;

        while (aux->next->next != NULL)
        {
            aux = aux->next;
        }

        pointerToLast = aux;
        aux->next = NULL;
    }

    void Lista::updatePositions ()
    {

        Node* aux = pointerToFirst;
        int positionNum = 1;

        while (aux != NULL)
        {
            aux->position = positionNum;
            positionNum++;
            aux = aux->next;
        }
    }

    int Lista::listLength ()
    {
        int i = 0;
        Node* aux = pointerToFirst;

        while (aux->next != NULL)
        {
            i++;
            aux = aux->next;
        }

        return i+1;
    }

    void Lista::saveList()
    {
        ofstream savingFile ("NomeRGSave.txt");
        Node* aux = pointerToFirst;

        if (savingFile.is_open())
        {
            while (aux != NULL)
            {
                savingFile << aux->name << "," << aux->rg << endl;
                aux = aux->next;
            }
            savingFile.close();
        }
        else cout << "Unable to open file";
    }
