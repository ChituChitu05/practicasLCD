//hacer una pila dede estructuras con menú.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

struct Persona{
    char nombre[30];
    int edad;
    char sexo;
};
struct Pila{
    struct Persona arreglo[TAM];
    struct Persona *ptrC;  
};

int meterPila(struct Pila *pila,struct Pila *dato){
    strcpy(pila->ptrC->nombre, dato->ptrC->nombre);  
    (pila ->ptrC) -> edad  = (dato ->ptrC) -> edad;
    (pila ->ptrC) -> sexo = (dato ->ptrC) -> sexo; 
    (pila -> ptrC)++;
    return 0;
}
struct Persona sacarPila(struct Pila *pila){
    (pila -> ptrC)--; 
    return *(pila -> ptrC);
}
int pilaLlena(struct Pila *pila){
    if(pila -> ptrC == &pila -> arreglo[TAM])
        return 1;
    
    return 0;
    
}
int pilaVacia(struct Pila *pila){
    if(pila -> ptrC == pila -> arreglo)
        return 1;
    
    return 0;
}
int menu(){
    int opc;
    printf("---Menú---\n");
    printf("1.Meter Pila\n");
    printf("2.Sacar Pila\n");
    printf("3.Salir\n");
    printf("Selecciona opcion:\n");
    scanf("%d",&opc);
    fflush(stdin);
    return opc;
}
int main(){
    struct Pila pila, *ptrp;
    ptrp = &pila;
    ptrp->ptrC = ptrp ->arreglo;
    struct Pila miPila, *miPtrp;
    miPtrp = &miPila;
    miPtrp -> ptrC = miPtrp -> arreglo;

    for(;;){
        switch (menu()){
        case 1:
            if(pilaLlena(ptrp)){
                printf("Pila Llena");
            }else{
                printf("Ingresa un nombre: ");
                gets((miPtrp  -> ptrC) -> nombre);
                fflush(stdin);
                printf("Ingresa una edad: ");
                scanf("%d",&(miPtrp  -> ptrC) -> edad);
                fflush(stdin);
                printf("Ingresa sexo:");
                (miPtrp  -> ptrC) -> sexo = getchar();
                fflush(stdin);
                meterPila(ptrp,miPtrp);
            }
            break;
        case 2:
            if(pilaVacia(ptrp)){
                printf("Pila Vacia.");
            }else{
                struct Persona datoRec;
                datoRec = sacarPila(ptrp);
                printf("Nombre: %s Edad: %d Sexo: %c",datoRec.nombre ,datoRec.edad, datoRec.sexo);
            }
            break;
        case 3:
            exit(1);
            break;
        default:
            break;
        }
    }

    return 0;
}
