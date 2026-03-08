//rellenar arreglo con apuntador simple
#include <stdio.h>
#define TAM 5
struct Dato{
    int arreglo[TAM];
    int i;
};


int main(){
    struct Dato dato;
    for(dato.i = 0; dato.i < TAM; (dato.i)++){
        printf("Ingresa un numero: \t");
        scanf("%d", &dato.arreglo[dato.i]);
    }
    for(dato.i = 0; dato.i < TAM; (dato.i)++){
        printf("En la celda %d esta el valor %d en la posicion %p \n", dato.i, dato.arreglo[dato.i], &dato.arreglo[dato.i]);
    }
    return 0;
}