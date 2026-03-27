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
int swap(int *arr,int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}
int partition (int *arr,int *start,int *end){
    
}
int main(){
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};


    return 0;
}