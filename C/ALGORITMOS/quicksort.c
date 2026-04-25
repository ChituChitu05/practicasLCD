/*
1. Seleccione un punto de pivote
El proceso comienza seleccionando un elemento conocido como pivote de la lista. Este puede ser cualquier elemento. Un pivote puede ser:

-Cualquier elemento al azar.
-El primer o el último elemento.
-Elemento central.

2. Reorganizar el arreglo
Ahora bien, el objetivo aquí es reorganizar la lista de tal manera que todos los elementos menores que el pivote queden a su izquierda, y todos los elementos mayores que el pivote queden a su derecha:

-El elemento pivote se compara con todos los elementos a partir del primer índice. Si el elemento es mayor que el elemento pivote, se añade un segundo puntero.
-Al compararlo con otros elementos, si se encuentra un elemento más pequeño que el elemento pivote, el elemento más pequeño se intercambia con el elemento más grande identificado previamente.

3. Dividir los subconjuntos
Una vez que hayamos particionado el arreglo, podemos dividir este problema en dos subproblemas. Primero, ordenamos el segmento del arreglo a la izquierda del pivote, y luego ordenamos el segmento del arreglo a la derecha del pivote.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Recibe: 
-La direccion del arreglo. 
-La direccion del primer primer elemento y el utimo del arreglo/subarreglo a ordenar.
*/

int swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int* particion(int *start,int *end){
    int *i;
    int *pivote = end;
    int *peque = start - 1;

    for(i = start; i < end; i++){
        if(*i < *pivote){
            peque++;
            swap(peque,i);
        }
    }
    swap(peque + 1, end);
    return peque + 1;
}

int quickSort(int *start,int *end){
    if(start >= end) return 0;

    int *pivote = particion(start,end);
    quickSort(start,pivote - 1);
    quickSort(pivote + 1,end);
    return 0;
}

//FUNCIONES AUXILIARES
int rellenarArreglo(int *ptrInicio,int *ptrFin){
    srand(time(NULL));
    for (; ptrInicio < ptrFin; ptrInicio++) {
        *ptrInicio = rand() % 100;  
    }
    return 0;
}
int imprimirArreglo(int *ptrInicio,int *ptrFin){
        printf("[");
    for (; ptrInicio < ptrFin; ptrInicio++) {
        printf(" %d ",*ptrInicio); 
    }
    printf("]");
    return 0;
}



int main(){
    /*Inicializar un arreglo de n numeros de enteros aleatoreos. */
    int arr[10];
    int *ptrStart, *ptrEnd;
    ptrStart = arr;
    ptrEnd = &arr[10];
    rellenarArreglo(ptrStart,ptrEnd);
    ptrStart = arr;
    printf("Arrgeglo creado: \n ");
    imprimirArreglo(ptrStart,ptrEnd);
    quickSort(ptrStart,ptrEnd);
    ptrStart = arr;
    printf("\nArreglo ordenado:\n ");
    imprimirArreglo(ptrStart,ptrEnd);
    
    return 0;
}

