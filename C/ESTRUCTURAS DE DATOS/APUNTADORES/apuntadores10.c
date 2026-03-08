//Rellenar arreglo usando apuntador doble fuera de estructura y apuntador simple dentro de estructura
#include <stdio.h>
#define TAM 5

struct Dato{
    int arreglo[TAM];
    int *ptr;
};

int main(){
    struct Dato dato,*ptrs,**ptrs2;
    ptrs = &dato;
    ptrs2 = &ptrs;
    for((*ptrs2) -> ptr = (*ptrs2) -> arreglo; (*ptrs2) -> ptr < &(*ptrs2) -> arreglo[TAM]; ((*ptrs2) -> ptr)++){
        printf("Ingresa un numero \t");
        scanf("%d", (*ptrs2)->ptr);
    }
    for((*ptrs2) -> ptr = (*ptrs2) -> arreglo; (*ptrs2) -> ptr < &(*ptrs2) -> arreglo[TAM]; ((*ptrs2) -> ptr)++){
        printf("En la celda %d esta el valor %d en la posicion %p \n", (int)((*ptrs2) -> ptr - (*ptrs2) -> arreglo), *(*ptrs2) -> ptr, (*ptrs2) -> ptr);
    }


    return 0;
}
