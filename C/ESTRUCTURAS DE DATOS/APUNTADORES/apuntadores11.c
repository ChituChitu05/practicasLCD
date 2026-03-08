//llenar arreglo con apuntador doble dentro de estructura y apuntador simple fuera de estructura
#include <stdio.h>
#define TAM 5
struct Dato{
    int arreglo[TAM];
    int *ptr,**ptr2;
};

int main(){
    struct Dato dato,*ptrs;
    ptrs = &dato;
    
    for(ptrs -> ptr = ptrs ->arreglo, ptrs ->ptr2 = &ptrs ->ptr; *ptrs -> ptr2 < &ptrs -> arreglo[TAM]; *ptrs -> ptr2 = *ptrs -> ptr2 +1){
        printf("\nIngresa un numero");
        scanf("%d",*ptrs -> ptr2);
    }
    for(ptrs -> ptr = ptrs ->arreglo, ptrs ->ptr2 = &ptrs ->ptr; *ptrs -> ptr2 < &ptrs -> arreglo[TAM]; *ptrs -> ptr2 = *ptrs -> ptr2 +1){
        printf("\nEn la celda %d esta el numero %d dn la direccion %p", (int)(*ptrs -> ptr2 - ptrs -> arreglo),**ptrs ->ptr2, *ptrs->ptr2);
    }
    return 0;
}