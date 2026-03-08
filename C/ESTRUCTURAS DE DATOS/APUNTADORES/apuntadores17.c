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
    int i;
};
int main(){
    struct Dato dato,*ptrs;
    ptrs = &dato;

    for(ptrs ->i = 0;ptrs ->i < TAM; (ptrs ->i) ++){
        printf("Ingrese Nombre: ");
        gets(ptrs -> arreglo[ptrs ->i].nombre);
        fflush(stdin);
        printf("Ingrese Edad: ");
        scanf("%d" , &ptrs -> arreglo[ptrs ->i].edad);
        fflush(stdin);
        printf("Ingrese Sexo: ");
        ptrs -> arreglo[ptrs ->i].sexo = getchar();
        fflush(stdin);
    }
    for(ptrs ->i = 0;ptrs ->i < TAM; (ptrs ->i) ++){
        printf("En la celda %d esta el nombre %s con la direccion %p con %d años con la direccion %p de sexo %c con la direccion %p.\n", 
                ptrs->i, ptrs -> arreglo[ptrs -> i].nombre,&ptrs -> arreglo[ptrs -> i].nombre,
                ptrs -> arreglo[ptrs -> i].edad, &ptrs -> arreglo[ptrs -> i].edad,
                ptrs -> arreglo[ptrs -> i].sexo,&ptrs -> arreglo[ptrs -> i].sexo);
    }
    return 0;
}