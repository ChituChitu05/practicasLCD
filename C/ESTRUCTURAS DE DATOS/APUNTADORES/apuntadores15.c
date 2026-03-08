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
    struct Dato dato;
    for(dato.i = 0; dato.i < TAM; dato.i++){
        printf("\nNombre: ");
        gets(dato.arreglo[dato.i].nombre);
        fflush(stdin);
        printf("\nEdad: ");
        scanf("%d",&dato.arreglo[dato.i].edad);
        printf("\nSexo: ");
        fflush(stdin);
        dato.arreglo[dato.i].sexo = getchar();
        fflush(stdin);
    }

    for(dato.i = 0; dato.i < TAM; dato.i++){
        printf("En la celda %d está %s, tiene %d años y es de sexo %c\n",dato.i,dato.arreglo[dato.i].nombre,dato.arreglo[dato.i].edad,dato.arreglo[dato.i].sexo);
    }
    return 0;
}