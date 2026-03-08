//rellenar arreglo de estructuras con apuntadores

#include <stdio.h>
//definicion de estructur (instancia) (antes del main)
struct Persona {
    char nombre[30];
    int edad;
    float alt;
    char sexo; 
};
int main(){

    struct Persona arreglo[5];
    int i;

    for(i = 0; i<5; i++){
        printf("Ingrese nombre:");
        gets(arreglo[i].nombre); //&arreglo[i].nombre[0] (direccion de inicio del arreglo)
        printf("Ingrese edad:");
        scanf("%d", &arreglo[i].edad); // &arreglo[i].edad direccion de la variable we
        printf("Ingrese altura:");
        scanf("%f", &arreglo[i].alt);
        fflush(stdin);     
        printf("Ingrese sexo:");
        arreglo[i].sexo = getchar();
        fflush(stdin);     
    }
    for(i = 0; i <5; ++i){
        printf("\n En la celda %d esta %s en la direccion %p \t %d en la direccion %p \t   %f en la direccion %p \t %c en la direccion %p", 
                i , arreglo[i].nombre,&arreglo[i].nombre, arreglo[i].edad, &arreglo[i].edad,arreglo[i].alt,&arreglo[i].alt,arreglo[i].sexo,&arreglo[i].sexo);
        
    }

    return 0;
}