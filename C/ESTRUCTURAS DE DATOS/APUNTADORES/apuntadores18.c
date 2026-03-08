//llenar arreglo de estructuras
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
    struct Dato dato,*ptrs;
    ptrs = &dato;

    for(ptrs -> ptr = ptrs -> arreglo;ptrs ->ptr < &ptrs -> arreglo[TAM]; (ptrs ->ptr)++){
        printf("Ingrese Nombre: ");
        gets(ptrs -> ptr -> nombre);
        fflush(stdin);
        printf("Ingrese Edad: ");
        scanf("%d" , &ptrs -> ptr ->edad);
        fflush(stdin);
        printf("Ingrese Sexo: ");
        ptrs -> ptr ->sexo = getchar();
        fflush(stdin);
    }
    for(ptrs -> ptr = ptrs -> arreglo;ptrs ->ptr < &ptrs -> arreglo[TAM]; (ptrs ->ptr)++){
        printf("En la celda %d esta el nombre %s con la direccion %p con %d años con la direccion %p de sexo %c con la direccion %p.\n", 
                (int)(ptrs -> ptr - ptrs -> arreglo), ptrs -> ptr -> nombre,&ptrs -> ptr -> nombre,
                ptrs -> ptr -> edad, &ptrs -> ptr -> edad,
                ptrs -> ptr -> sexo,&ptrs -> ptr -> sexo);
    }

    return 0;
}