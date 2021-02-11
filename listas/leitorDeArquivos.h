#ifndef LEITORDEARQUIVOS_H
#define LEITORDEARQUIVOS_H

#include "Lista.h"

class Reader{
public:

    int lineCounter(string fileName);
    void geradorEncadeada(string fileName, Lista* myList);

};

#endif // LEITORDEARQUIVOS_H
