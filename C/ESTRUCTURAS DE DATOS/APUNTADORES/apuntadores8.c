//rellenar arreglo con apuntador dentro de estructura

#include <stdio.h>
#define TAM 5

struct Dato{
    int arreglo[TAM];
    int *ptr;
};


int main(){
    struct Dato dato;
    for(dato.ptr = dato.arreglo;dato.ptr < &dato.arreglo[5];(dato.ptr)++){
        printf("Ingresa un número: \t");
        scanf("%d", dato.ptr);
    }
    for(dato.ptr = dato.arreglo;dato.ptr < &dato.arreglo[5];(dato.ptr)++){
        printf("En la celda %d esta el número %d en la posicion %p \n", (int)(dato.ptr - dato.arreglo) , *dato.ptr , dato.ptr);
    }
}