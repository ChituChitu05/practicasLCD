/*
Lista enlazada con funiones
*/

#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int dato;              // valor guardado en el nodo
    struct Nodo *ptrSig;   // dirección del siguiente nodo
};
int crearNodo(struct Nodo *nodo){
    return (struct Nodo*) malloc(sizeof(struct Nodo));
}
