//llenar arreglo de estructuras con apuntador simple en estructura
#include <stdio.h>
#define TAM 5
struct Persona{
    char nombre [30];
    int edad;
    char sexo;
};

struct Dato{
    struct Persona arreglo[TAM];
    struct Persona *ptr;
};

int main(){
    struct Dato dato;

    for(dato.ptr = dato.arreglo; dato.ptr < &dato.arreglo[TAM]; dato.ptr++){
        printf("Ingresa nombre: ");
        gets(dato.ptr -> nombre);
        fflush(stdin);
        printf("Ingresa edad: ");
        scanf("%d", dato.ptr -> edad);
        fflush(stdin);
        printf("Ingresa sexo: ");
        dato.ptr -> sexo = getchar();
        fflush(stdin);
    }
    for(dato.ptr = dato.arreglo; dato.ptr < &dato.arreglo[TAM]; dato.ptr++){
        printf("En la celda %d está %s, tiene %d años y es de sexo %c\n",(int)(dato.ptr - dato.arreglo),dato.ptr->nombre,dato.ptr -> edad ,dato.ptr -> sexo);
    }
    return 0;
}