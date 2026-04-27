// lista puntero simple (con cabecera)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dato{
    char nombre[30];
    int edad;
};

struct Nodo{
    int key;
    struct Dato dato;    
    struct Nodo *ptrSig,*ptrAnt; 
};

