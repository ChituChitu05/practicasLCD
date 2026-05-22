#include <stdio.h>
#include <stdlib.h>
struct Nodo{
    int dato;
    struct Nodo *ptrIzq;
    struct Nodo *ptrDer;
};
struct Nodo *createNodo(int dato){
    struct Nodo *newNodo;
    newNodo = (struct Nodo *) malloc(sizeof(struct Nodo));
    newNodo -> dato = dato;
    newNodo -> ptrDer = NULL;
    newNodo -> ptrIzq = NULL;
    return newNodo;
}
int insertarNodo(struct Nodo **ptrRaiz,int dato){
    if(*ptrRaiz == NULL){
        *ptrRaiz = createNodo(dato);
    }else if(((*ptrRaiz)->dato)>dato){
        insertarNodo(&((*ptrRaiz)->ptrIzq),dato);
    }else{
        insertarNodo(&((*ptrRaiz)->ptrDer),dato);
    }
}
void imprPreorder(struct Nodo **ptrRef){
    struct Nodo *ptrRec;
    ptrRec = *ptrRef;
    if(ptrRec != NULL){
        printf("\n Dato: %d ",ptrRec->dato);
        imprPreorder(&(ptrRec->ptrIzq));
        imprPreorder(&(ptrRec->ptrDer));
    }

}
void imprPostorder(struct Nodo **ptrRef){
    struct Nodo *ptrRec;
    ptrRec = *ptrRef;
    if(ptrRec != NULL){
        printf("\n Dato: %d ",ptrRec->dato);
        imprPostorder(&(ptrRec->ptrIzq));
        imprPostorder(&(ptrRec->ptrDer));
    }
}
void imprimirInorder(struct Nodo **ptrRef){
    struct Nodo *ptrRec;
    ptrRec = *ptrRef;
    if(ptrRec != NULL){
        imprimirInorder(&(ptrRec->ptrIzq));
        printf("\n Dato: %d ",ptrRec->dato);
        imprimirInorder(&(ptrRec->ptrDer));
    }
}
int menu(){
    int opc;
    printf("\nMenu");
    printf("\n1.Meter");
    printf("\n2.Imprimir inorder");
    printf("\n3.Imprimir preorder");
    printf("\n4.Imprimir postorder");
    printf("\n5.Salir");
    printf("\nIngresa opcion:");
    scanf("%d",&opc);
    return opc;
}
int main(){
    struct Nodo *ptrRef1,**ptrRef2;
    int dato;
    ptrRef1 = NULL;
    ptrRef2 = &ptrRef1;

    for(;;){
        switch (menu()){
        case 1:
            printf("\nIngrese un entero:");
            scanf("%d",&dato);
            insertarNodo(ptrRef2,dato);
            break;
        case 2:
            imprimirInorder(ptrRef2);
            break;
        case 3:
            imprPreorder(ptrRef2);
            break;
        case 4:
            imprPostorder(ptrRef2);
            break;
        case 5:
            exit(0);
            break;    
        default:
            printf("\nIngrese opcion correcta");
            break;
        }
    }

    return 0;
}