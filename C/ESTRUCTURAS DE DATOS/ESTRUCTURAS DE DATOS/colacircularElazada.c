//cola circular con una lista enlazada  
#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int dato;
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};

struct Nodo *crearNodo(int dato){
    struct Nodo *nodoNuevo;
    nodoNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nodoNuevo -> ptrAnt = NULL;
    nodoNuevo -> ptrSig = NULL;
    nodoNuevo -> dato = dato;
    return nodoNuevo;
}
int meterDato(struct Nodo *ptrRef, int dato){
    
    return 0;
}