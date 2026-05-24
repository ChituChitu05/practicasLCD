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
int imprimirArbol(struct Nodo *ptrRaiz,int contador){
    int i,j;
    i = contador;
    if(ptrRaiz != NULL){
        imprimirArbol(ptrRaiz -> ptrDer,i++);
        printf("\n");
        for(j=1;j < i; j++) printf(" - ");
        printf(" %d ",ptrRaiz -> dato);
        imprimirArbol(ptrRaiz -> ptrIzq,i++);
    }
    return 0;
}
int menu(){
    int opc;
    printf("\nMenu");
    printf("\n1.Meter");
    printf("\n2.Imprimir todo");
    printf("\n3.Salir");
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
            imprimirArbol(*ptrRef2,1);
            break;
        case 3:
            exit(0);
            break;    
        default:
            printf("\nIngrese opcion correcta");
            break;
        }
    }

    return 0;
}