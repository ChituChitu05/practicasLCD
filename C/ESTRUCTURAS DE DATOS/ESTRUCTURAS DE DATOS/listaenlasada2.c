#include <stdio.h>
#include <stdlib.h>
struct Nodo{
    int dato;
    struct Nodo *ptrSig; 
};

int main(){
    struct Nodo *ptrRef, *ptrRec,*ptrNuevo, *ptrBasura;
    int miDato;

    /*
    CADA NODO NUEVO CREADO DESPUES DEL DE REFERENCIA SE AÑADE ENTRE EL NODO REFERENCIA Y LOS NODOS YA EXISTENCIAS
    */

    //---CREARR NODO CABECERA---
    ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo)); 
    ptrNuevo -> dato = -1000;
    ptrNuevo -> ptrSig = NULL; 
    //---MOVER EL NODO NUEVO AL DE REFERENCIA--- 
    ptrRef = ptrNuevo;
    //---CREAR NUEVO NODO---
    ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo)); 
    printf("Ingrese Dato Entero: ");
    scanf("%d", & ptrNuevo -> dato);
    ptrNuevo -> ptrSig = NULL;
    //---ENLASAR EL NODO CBECERA AL NUEVO NODO CREADO---
    ptrRef -> ptrSig = ptrNuevo; 
    //---CREAR NUEVO NODO---
    ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo)); 
    printf("Ingrese Dato Entero: ");
    scanf("%d", & ptrNuevo -> dato);
    ptrNuevo -> ptrSig = NULL;

    ptrNuevo -> ptrSig = ptrRef -> ptrSig;
    ptrRef -> ptrSig = ptrNuevo;
    
    ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo)); 
    printf("Ingrese Dato Entero: ");
    scanf("%d", & ptrNuevo -> dato);
    ptrNuevo -> ptrSig = NULL;

    ptrNuevo -> ptrSig = ptrRef -> ptrSig;
    ptrRef -> ptrSig = ptrNuevo;

    //Recorrer lista enlasada.
    while(ptrRec->ptrSig != NULL){
        printf("Dato: %d en la posicion %p", ptrRec->dato,ptrRec);
        ptrRec = ptrRec -> ptrSig;
    }

    

    return 0;
}
