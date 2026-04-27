//Lista con cabecera y ass-endente (alfanumerico)
#include <stdio.h>
#include <stdlib.h>
struct Nodo{
    int key;
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};
