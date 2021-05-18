#ifndef LEITORSEQ_H
#define LEITORSEQ_H
#include "NodeSeq.h"

class ReaderSeq{
    public:

    int lineCounter(string fileName);
    void geradorSeq(string fileName, NodeSeq myVector[]);
};

#endif // LEITORSEQ_H
