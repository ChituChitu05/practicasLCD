/*
Funcion de una Pila:
Ultimo en Entrar -> Primero en Salir
Last In -> First Out (LIFO)

-Solo se necesitan 2 funciones principales (pop y push).
-Se usan funciones auxiliares para verificar si está llena o vacía.
-El puntero en la estructura nunca debe de ser modificado por otras funciones que no sean Push (Meter) y Pop (eliminar).
-meterPila() -> Mete el dato en la pila e incrementa en 1 el puntero.
-sacarPila() -> Devuelve el ultimo elemento y decrementa en 1 el puntero.
-Antes de añadir o eliminar un dato se tiene que verificar que la pila no este llena o vacia comparando en que posicion se encuentra el apuntador. 
-El apuntador siempre apunta a la siguiente posición libre.
  1,2,3,4,...,...,...
           ^
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 5
struct  Pila{
    int arreglo[TAM];
    int *ptrC;
};

int meterPila(struct Pila *ptrp, int dato){
    *ptrp -> ptrC = dato; 
    (ptrp -> ptrC)++; 
    return dato;
}
int sacarPila(struct Pila *pila){
    (pila ->ptrC)--; 
    return *pila ->ptrC;
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
    printf("\n-----------Menú-----------");
    printf("\n 1. Meter Dato");
    printf("\n 2. Sacar Dato");
    printf("\n 3. Salir");
    printf("\nIngrese opcion: ");
    scanf("%d",&opc);
    return opc;
}

int main(){
    struct Pila pila,*miPtrp;
    int miDato;

    miPtrp = &pila;
    miPtrp -> ptrC = miPtrp -> arreglo;
    
    for(;;){
        switch (menu()){
        case 1:
            if(pilaLlena(miPtrp)){
                printf("La pila esta llena.");
            }else{
                printf("Ingrese dato: ");
                scanf("%d",&miDato);
                printf("Dato Guardado: %d.",meterPila(miPtrp,miDato));
            }
            break;
        case 2:
            if(pilaVacia(miPtrp)){
                printf("La pila esta Vacia.");
            }else{
                printf("Dato Eliminado: %d.",sacarPila(miPtrp));
            }
            break;
        case 3:
            exit(0);
            break;
        
        default:
            printf("Opcion Invalida");
            break;
        }
    }

    return 0;
}