//cola circular con una lista enlazada  
#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int dato;
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};

