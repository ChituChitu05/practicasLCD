// lista puntero doble (sin cabecera) alfanumerico
#include <stdio.h>
#include <stdlib.h>

struct Dato{
    char nombre[30];
    int edad;
};

struct Nodo{
    struct Dato dato;
    int clave;
    struct Nodo *ptrSig,*ptrAnt; 
};

struct Nodo* crearNodo(struct Dato* dato){

}

