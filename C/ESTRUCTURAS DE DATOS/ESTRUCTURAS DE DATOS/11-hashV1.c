//Lista con cabecera y ass-endente
/*
Lista: Los nodos de lalista se ingresan a un campo llamado clave o llave(key) ordenados de menosr a mallor
para sacar se realiza un recorrido hasata hacer match en el elemento.
*/
//tarea: -key mumerica -key alfanumerica
#include <stdio.h>
#include <stdlib.h>
struct Nodo{
    int key;
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};

struct Nodo *crearNodo(int dato){
    struct Nodo *nodoNuevo;
    nodoNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nodoNuevo -> ptrSig = NULL;
    nodoNuevo -> ptrAnt = NULL;
    nodoNuevo -> key = dato;
    return nodoNuevo;
}

int meterNodo(struct Nodo *ptrRef1,int dato){
    struct Nodo *newNodo;
    struct Nodo *ptrRecorrer;
    newNodo = crearNodo(dato);
    if(ptrRef1 -> ptrSig == NULL){
        ptrRef1 -> ptrSig = newNodo;
        newNodo -> ptrAnt = ptrRef1;
    }else{
    }
    return 0;
}
int main(){
    struct Nodo *ptrRef;
    ptrRef = crearNodo(-10000);

    for(int i = 0; i < 35;++i){
        int r = rand();
    }
    return 0;
}