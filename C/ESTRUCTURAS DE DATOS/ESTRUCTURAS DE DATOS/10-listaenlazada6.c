//con nodo de cabecera
//terminar
#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int dato;
    struct Nodo *ptrSig,*ptrAnt;
};
struct Nodo *crearNodo(int *dato){
    struct Nodo*ptrNew;
    ptrNew = (struct Nodo*) malloc(sizeof(struct Nodo));
    ptrNew -> ptrSig = NULL;
    ptrNew -> ptrAnt = NULL;
    ptrNew -> dato = *dato; 
    return ptrNew;
}

int meterNodo(struct Nodo *ptrRef, int *dato){
    struct Nodo *ptrNew;

    ptrNew = crearNodo(dato);
    if(ptrRef -> ptrSig == NULL && ptrRef -> ptrAnt == NULL){
        ptrRef -> ptrSig = ptrNew;
        ptrNew -> ptrAnt = ptrRef;
    }else{
        ptrNew -> ptrSig = ptrRef -> ptrSig;
        ptrRef -> ptrSig -> ptrAnt = ptrNew;
        ptrRef -> ptrSig = ptrNew;
        ptrNew -> ptrAnt = ptrRef;
    }
    return 0;
}


int imprimirTodo(struct Nodo *ptrRef){
    struct Nodo *ptrRec;
    ptrRec = ptrRef -> ptrSig;
    printf("\nImprimir Normal");
    while(ptrRec != NULL){
        printf("\nDato: %d",ptrRec ->dato);
        ptrRec = ptrRec -> ptrSig;
    }
    return 0;
}
int imprimirTodoRev(struct Nodo *ptrRef){
    struct Nodo *ptrRec;
    ptrRec = ptrRef->ptrSig;
    while(ptrRec -> ptrSig != NULL){
        ptrRec = ptrRec -> ptrSig;
    }
    printf("\nImprimir Rev");
    while(ptrRec -> ptrAnt != NULL){
        printf("\nDato: %d",ptrRec ->dato);
        ptrRec = ptrRec -> ptrAnt;
    }
    return 0;
}
int main(){
    struct Nodo *ptrRef;
    int dato;
    dato = -10000;
    ptrRef = crearNodo(&dato);
    for(int i = 5; i <= 25; i+=5){
        dato = i;
        meterNodo(ptrRef,&dato);
    }
    imprimirTodo(ptrRef);
    imprimirTodoRev(ptrRef);
    return 0;
}