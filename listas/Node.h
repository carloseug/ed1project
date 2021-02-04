#include <new>
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

class Node{
public:
    int rg;
    int position;
    string name;
    Node* next;

    Node(string newName, int newRg)
    {
        name = newName;
        rg = newRg;

        next = NULL;
    }
};
