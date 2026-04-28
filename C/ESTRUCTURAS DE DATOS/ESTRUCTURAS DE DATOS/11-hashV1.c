#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int key;
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};

struct Nodo* createNodo(int key) {
    struct Nodo* nodoNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nodoNuevo->key = key;
    nodoNuevo->ptrSig = NULL;
    nodoNuevo->ptrAnt = NULL;
    return nodoNuevo;
}

int meterNodo(struct Nodo *ptrRef, int key) {
    struct Nodo *ptrRec,*ptrAtras; 
    ptrRec = ptrRef->ptrSig;
    ptrAtras = ptrRef;

    while (ptrRec != NULL && key >= ptrRec->key) {
        if (ptrRec->key == key) {
            return 1;
        }
        ptrAtras = ptrRec;
        ptrRec = ptrRec->ptrSig;
    }

  
    struct Nodo *ptrNew;
    ptrNew = createNodo(key);


    ptrNew->ptrSig = ptrRec;
    ptrNew->ptrAnt = ptrAtras;
    ptrAtras->ptrSig = ptrNew;


    if (ptrRec != NULL) {
        ptrRec->ptrAnt = ptrNew;
    }

    return 0;
}

void mostrar(struct Nodo *ptrRef) {
    struct Nodo *temp = ptrRef->ptrSig;
    printf("Lista: ");
    while (temp != NULL) {
        printf("[%d] ", temp->key);
        temp = temp->ptrSig;
    }
    printf("\n");
}

int main() {
    // Nodo cabecera (dummy)
    struct Nodo *cabecera = createNodo(-1);

    meterNodo(cabecera, 20);
    meterNodo(cabecera, 10);
    meterNodo(cabecera, 30);
    meterNodo(cabecera, 15);

    mostrar(cabecera);

    return 0;
}