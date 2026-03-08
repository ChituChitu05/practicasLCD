/*
Listas enlasadas:
Lista enlazada con head, donde el primer nodo siempre es el de referencia(tambien llamado cabeza, head).
Se crean nodos que se agregan esntre el head y el pimer nodo creado despues del head.
La informacion de TODOS los nodos aqui son 2 elementos, el dato a guardar y la direccion del siguiente elemento.
*/

#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int dato;
    struct Nodo *ptrSig;
};

int main(){
    /*
    ptrRef sera el ocupado por el nod HEAD.
    ptrNuevo se utilizara para crear nuevos nodos que despues se enlazaran con los nuevos nodos creados y el HEAD para poder reutilizarse.
    ptrBasura se utilizara para poder guardar la direccion del nodo a ser eliminado sin perder informacion que conteniía y poder reenlazar los nodos entre los que se encontraba.
    ptrRec se utilizara para recorrer toda la lista desde el nodo de referencia hasta el ultimo nodo culla direccion de "siguiente nodo" sea NULL.

    */
    struct Nodo *ptrRef,*ptrNuevo, *ptrBasura,*ptrRec;
    


    //el primer nodo en crearse manualmente sera el de Regerencia (head) que se le asignara despues a su puntero correspondiente.    
    ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo)); //aparta memoria en tiempo de ejecucion para un nuevo nodo del tamaño que estos requieran.
    ptrNuevo -> dato = -1000; //el dato del nodo de referencia se asigna a -1000 para poder identificarlo facilmente. 
    ptrNuevo -> ptrSig = NULL; //el nodo de referencia no apunta a ningun nodo por lo que su puntero de siguiente nodo se asigna a NULL.

    ptrRef = ptrNuevo;  //el nodo de referrencia se asigna al puntero de referencia para poder acceder a el posteriormente y no perder su direccion.

    //primer elemento real añadido a la lista
    ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    ptrNuevo -> dato = 5; //de momento se añadira el 5 a la lista, se puede cambiar por un scanf para ñadirlo manualmente.
    ptrNuevo -> ptrSig = NULL; //el primer elemento añadido a la lista siempre terminara siendo el ultimo en la lista.

    ptrRef -> ptrSig = ptrNuevo; //enlazamos el nodo referencia a la direccion previamente reservada con malloc para poder reutilizar ptrNuevo.
    
    //segndo nodo
    ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    ptrNuevo -> dato = 10;

    ptrNuevo -> ptrSig = ptrRef -> ptrSig;
    ptrRef -> ptrSig = ptrNuevo;

    //tercer nodo
    ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    ptrNuevo -> dato = 15;

    ptrNuevo -> ptrSig = ptrRef -> ptrSig;
    ptrRef -> ptrSig = ptrNuevo;



    //recorrer
    // deberia de imprimir 15,10,5

    ptrRec = ptrRef;//DEBE DE ASIGNARSE A UN PUNTERO NUEVO PARO ANO ALTERAR LA POSICION DEL NODO REFERENCIA Y PERDER EL INICIO DE LA CADENA
    while (ptrRec->ptrSig != NULL){
        printf("El dato almacenado es: %d en la direccion %p", ptrRec ->dato,ptrRec);
        ptrRec = ptrRec -> ptrSig;
    }   
    


    return 0;
}