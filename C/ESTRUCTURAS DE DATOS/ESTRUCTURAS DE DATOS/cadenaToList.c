//pasar cadena a lista sin cabecera
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo{
    char key;
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};

struct Nodo *crearNodo(char *dato){
    struct Nodo *nodoNuevo;
    nodoNuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
    strcpy(nodoNuevo -> key,*dato);
    nodoNuevo -> ptrSig = NULL;
    nodoNuevo -> ptrSig = NULL;
    return nodoNuevo; 
}

int meterDato(struct Nodo **ptrRef2, char dato){
    struct Nodo *newNodo;
    newNodo = crearNodo(dato);
    if(*ptrRef2 == NULL){
        (*ptrRef2) -> ptrSig = newNodo;
        newNodo -> ptrAnt = *ptrRef2;
    }else{
        newNodo -> ptrSig = (*ptrRef2) -> ptrSig;
        newNodo -> ptrAnt = *ptrRef2;
        (*ptrRef2) -> ptrSig -> ptrAnt = newNodo;
        (*ptrRef2) -> ptrSig = newNodo;  
    }
    return 0;
}
int printList(struct Nodo **ptrRef2){
    struct Nodo *ptrRec;
    ptrRec = (*ptrRef2);
    if(ptrRec == NULL){
        pribtf("Lista Vacia");
    }else{
        while(ptrRec != NULL){
            printf("%c", ptrRec -> key);
            ptrRec = ptrRec ->ptrSig;
        }
    }
    return 0;
}

int main(){
    char cadena[30] = "ASDFGHKLÑ";
    char *caracter;
    struct Nodo *ptrRef1, **ptrRef2;
    ptrRef1 = NULL;
    *ptrRef2 = &ptrRef1;
    for(caracter = cadena; caracter < &cadena[30]; caracter++){
        meterDato(ptrRef2, &caracter);
    }
    printf(ptrRef2);
    return 0;
}