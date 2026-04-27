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

struct Nodo *crearNodo(int key,struct Dato *ptrD){
    struct Nodo *nodoNew;
    nodoNew = (struct Nodo *) malloc(sizeof(struct Nodo));
    nodoNew -> key = key; 
    nodoNew -> dato.edad = ptrD -> edad;
    strcpy(nodoNew -> dato.nombre, ptrD -> nombre);
    nodoNew -> ptrAnt = NULL;
    nodoNew -> ptrSig = NULL;
    return nodoNew;
}
int meterDato(struct Nodo *ptrRef,int key,struct Dato *ptrD){

}
int main(){


    return 0;
}