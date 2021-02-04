#ifndef LISTA_H
#define LISTA_H

#include "Node.h"

class Lista{
public:

    Node* pointerToFirst = NULL;
    Node* pointerToLast = NULL;

    void insertFirstNode (Node* newFirstNode);
    void insertNode (Node* newNode);
    void insertMidNode (Node* previousNode, Node* newNode);
    void showInfo (int userPosition);
    void showListInfo ();
    void removeFirstNode ();
    void removeMidNode (int positionK);
    void removeLastNode ();
    void updatePositions ();
    int listLength ();
    void saveList();

};

#endif // LISTA_H
