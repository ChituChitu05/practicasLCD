//llenar apuntador con apuntero doble fuera de 
#include <stdio.h>
#define TAM 5
struct Dato{
    int arreglo[TAM];
    int *ptr;
};

int main(){
    struct Dato dato,*ptrs1,**ptrs2;
    ptrs2 = &ptrs1;
    ptrs1 = &dato;

    for((*ptrs2) -> ptr = (*ptrs2) -> arreglo; (*ptrs2) -> ptr < &(*ptrs2) -> arreglo[TAM]; ((*ptrs2) -> ptr)++){
        printf("\n Ingresa un numero: ");
        scanf("%d",(*ptrs2) -> ptr);
    }
    for((*ptrs2) -> ptr = (*ptrs2) -> arreglo; (*ptrs2) -> ptr < &(*ptrs2) -> arreglo[TAM]; ((*ptrs2) -> ptr)++){
        printf("\n En la celda %d esta el valor %d con la direccion %p.", (int)((*ptrs2) -> ptr - (*ptrs2) -> arreglo), *(*ptrs2) -> ptr, (*ptrs2) -> ptr);
    }


    return 0;
}