#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int key;
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};

struct Nodo *createNodo(int key)
{
    struct Nodo *nodoNuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nodoNuevo->key = key;
    nodoNuevo->ptrSig = NULL;
    nodoNuevo->ptrAnt = NULL;
    return nodoNuevo;
}

int meterNodo(struct Nodo *ptrRef, int key)
{
    struct Nodo *ptrRec, *ptrAtras;
    ptrRec = ptrRef->ptrSig;
    ptrAtras = ptrRef;

    while (ptrRec != NULL && key >= ptrRec->key)
    {
        if (ptrRec->key == key)
        {
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

    if (ptrRec != NULL)
    {
        ptrRec->ptrAnt = ptrNew;
    }

    return 0;
}

int imprimir(struct Nodo *ptrRef)
{
    struct Nodo *ptrRec;
    ptrRec = ptrRef->ptrSig;
    while (ptrRec != NULL)
    {
        printf("%d\n", ptrRec->key);
        ptrRec = ptrRec->ptrSig;
    }
    return 0;
}

int sacarDato(struct Nodo* ptrRef, int* dato){
    struct Nodo* ptrBasura; 
    return 0;
}
int menu()
{
    int opc;
    printf("\nMenu");
    printf("\n1.Meter");
    printf("\n2.Sacar");
    printf("\n3.Imprimir todo");
    printf("\n4.Salir");
    printf("\nIngresa opcion:");
    scanf("%d", &opc);
    return opc;
}

int main()
{
    struct Nodo *ptrRef = createNodo(-1);
    int dato;

    switch (menu()){
    case 1:
        scanf("%d",&dato);
        meterNodo(ptrRef,dato);
        break;
    case 2:
        /* code */
        break;
    case 3:
        imprimir(ptrRef);
        break;
    case 4:
        exit(1);
        break;

    default:
        printf("Opcion incorrecta");
        break;
    }
    return 0;
}