//rellenar areglo con apuntador fuera de estructura
#include <stdio.h>
#define TAM 5

struct Dato{
    int arreglo [TAM];
    int i;
};

int main(){
    struct Dato dato,*ptrs;
    ptrs = &dato;
    for(ptrs->i = 0; ptrs->i < TAM; (ptrs->i)++){
        printf("Ingresa un numero: \t");
        scanf("%d", &ptrs->arreglo[ptrs->i]);
    }
    for(ptrs->i = 0; ptrs->i < TAM; (ptrs->i)++){
        printf("En la celda %d esta el valor %d en la posicion %p \n", ptrs->i, ptrs->arreglo[ptrs->i], &ptrs->arreglo[ptrs->i]);
    }
    return 0;
}