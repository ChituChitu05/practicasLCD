//ingresar e imprimir numeros a un arreglo con apunhtador

#include <stdio.h>
int arreglo[5];
int *ptr;
int main() {
    for(ptr = arreglo;ptr < &arreglo[5];ptr++){
        printf("Ingrese un número: \t");
        scanf("%d", ptr);
    }
    for(ptr = arreglo; ptr < &arreglo[5];ptr++){
        printf("en la celda %d esta el valor %d en la posicion %p \n", (int)(ptr-arreglo),*ptr, ptr);

    }
    return 0;
}