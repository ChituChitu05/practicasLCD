// lista puntero simple (con cabecera)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dato{
    char nombre[30];
    int edad;
};

struct Nodo{
    struct Dato dato;
    int key;
    struct Nodo *ptrSig,*ptrAnt; 
};

struct Nodo* crearNodo(struct Dato* dato,int key){
    struct Nodo* nodoNuevo;
    nodoNuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodoNuevo -> ptrAnt = NULL;
    nodoNuevo -> ptrSig = NULL;
    nodoNuevo -> dato.edad = dato -> edad;
    strcpy(nodoNuevo -> dato.nombre, dato->nombre);
    nodoNuevo -> key = key;
    return nodoNuevo;
}

int meterNodo(struct Nodo *ptrRef, struct Dato *dato,int key){
    struct Nodo* ptrNew;
    struct Nodo* ptrRec;
    ptrRec = ptrRef -> ptrSig;
    ptrNew = crearNodo(dato,key);
    printf("%p",ptrNew);
    if(ptrRef -> ptrSig == NULL){
        ptrNew -> ptrAnt = ptrRef;
        ptrRef -> ptrSig = ptrNew;
        return 0;
    }else{
        while(ptrRec != NULL){
            if(ptrRec -> key == ptrNew ->key){
                return 1;
            }
            ptrRec = ptrRec ->ptrSig;
        }
        while(ptrNew -> key < ptrRec -> key){
            ptrRec = ptrRec ->ptrSig;
        }
        ptrNew -> ptrAnt = ptrRec ->ptrAnt;
        ptrNew -> ptrSig = ptrRec;
        ptrRec -> ptrAnt -> ptrSig = ptrNew;
        ptrRec -> ptrAnt = ptrNew;
        return 0;
    }
}
intimprimir(){
    
}
int main(){
    struct Nodo* ptrRef;
    struct Dato dato,*ptrD;
 
    ptrD = &dato;
    ptrD -> edad = -1000;
    strcpy(ptrD->nombre,"uwur");

    printf("%p", ptrRef);
    for(int i = 0; i <= 10; ++i){
        printf("%d\n",i);
        int random = (rand() % (10 - 1 + 1)) + 1;
        ptrD -> edad = i+1;
        strcpy(ptrD -> nombre,"AAA"+random);
    }

}
