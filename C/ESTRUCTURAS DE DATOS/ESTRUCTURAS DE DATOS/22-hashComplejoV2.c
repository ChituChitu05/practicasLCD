// lista puntero doble (sin cabecera) numerico
//terminar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Dato{
    char nombre[30];
    int edad;
};

struct Nodo{
    struct Dato dato;
    int clave;
    struct Nodo *ptrSig,*ptrAnt; 
};

struct Nodo* crearNodo(struct Dato* dato, int clave){
    struct Nodo *newNodo;
    newNodo = (struct Nodo *) malloc(sizeof(struct Nodo));
    newNodo -> dato.edad = dato -> edad;
    strcpy(newNodo -> dato.nombre,dato ->nombre);
    newNodo -> ptrAnt = NULL;
    newNodo -> ptrSig = NULL;
    newNodo -> clave = clave;
    return newNodo;
}

int meterNodo(struct Nodo **ptrRef, struct Dato *ptrD,int clave){
    struct Nodo *nodoNuevo,*ptrAv,*ptrAtr;
    nodoNuevo = crearNodo(ptrD,clave);
    if((*ptrRef) == NULL){
        *ptrRef = nodoNuevo;
        return 0;
    }
    if(clave < ((*ptrRef) -> clave)){
        nodoNuevo -> ptrSig = *ptrRef;
        (*ptrRef) -> ptrAnt = nodoNuevo; 
        *ptrRef = nodoNuevo;
        return 0;
    }
    ptrAv = *ptrRef;
    while(ptrAv != NULL){
        if(ptrAv -> clave == clave) {
            free(nodoNuevo);
            return 1;
        }
        ptrAv = ptrAv ->ptrSig;
    }

    ptrAv = (*ptrRef) -> ptrSig;
    ptrAtr = *ptrRef;

    while(ptrAv != NULL && ptrAv -> clave < clave){
        ptrAtr = ptrAv;
        ptrAv = ptrAv ->ptrSig;
    }

    if(ptrAv == NULL){
        nodoNuevo -> ptrAnt = ptrAtr;
        nodoNuevo -> ptrSig = NULL;
    }else{
        nodoNuevo -> ptrSig = ptrAv;
        nodoNuevo -> ptrAnt = ptrAtr;
        ptrAtr -> ptrSig = nodoNuevo;
        ptrAv -> ptrAnt = nodoNuevo;
    }

    return 0;
}

int main(){
    struct Nodo *ptrRef1,**ptrRef2;
    ptrRef1 = NULL;
    ptrRef2 = &ptrRef1;
    
    


    return 0;
}