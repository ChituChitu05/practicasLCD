//llenar arreglo de estructuras con aapuntador doble y simple en estructura;
#include <stdio.h>
#define TAM 5
struct Persona{
    char nombre [30];
    int edad;
    char sexo;
};

struct Dato{
    struct Persona arreglo[TAM];
    struct Persona *ptr1,**ptrs2;
};

int main(){
    struct Dato dato;
    dato.ptrs2 = &dato.ptr1;
    for(*dato.ptrs2 = dato.arreglo;*dato.ptrs2 < &dato.arreglo[TAM];(*dato.ptrs2)++){
        printf("Ingrese Nombre: ");
        gets((*dato.ptrs2) -> nombre);
        fflush(stdin);
        printf("Ingrese Edad: ");
        scanf("%d" , &(*dato.ptrs2) -> edad);
        fflush(stdin);
        printf("Ingrese Sexo: ");
        (*dato.ptrs2) -> sexo = getchar();
        fflush(stdin);
    }
    for(*dato.ptrs2 = dato.arreglo;*dato.ptrs2 < &dato.arreglo[TAM];(*dato.ptrs2)++){
        printf("En la celda %d esta el nombre %s con la direccion %p con %d años con la direccion %p de sexo %c con la direccion %p.\n", 
        (int)(*dato.ptrs2 - dato.arreglo), (*dato.ptrs2) -> nombre, &(*dato.ptrs2) -> nombre,
        (*dato.ptrs2) -> edad, &(*dato.ptrs2) -> edad,
        (*dato.ptrs2) -> sexo, &(*dato.ptrs2) -> sexo);
    }

    return 0;
}