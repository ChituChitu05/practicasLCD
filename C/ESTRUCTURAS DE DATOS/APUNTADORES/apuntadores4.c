//rellenar arreglo con apuntador doble

#include <stdio.h>
#define TAM 5
int main(){
    int arreglo[TAM];
    int *ptr1, **ptr2;
    for(ptr1 = arreglo, ptr2 = &ptr1;*ptr2 < &arreglo[TAM]; (*ptr2)++){
        printf("\nIntroduce un numero: ");
        scanf("%d", *ptr2);
    }
    for(ptr1 = arreglo, ptr2 = &ptr1; *ptr2 < &arreglo[TAM]; (*ptr2)++){
        printf("\n en la celda %d está el  valor %d en la direccion %p",(int) (*ptr2-arreglo),**ptr2,*ptr2);
    }
    return 0;
}