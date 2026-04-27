//Lista con cabecera y ass-endente(alfanumerico)
/*
Lista: Los nodos de lalista se ingresan a un campo llamado clave o llave(key) ordenados de menosr a mallor
para sacar se realiza un recorrido hasata hacer match en el elemento.
*/
#include <stdio.h>
#include <stdlib.h>
struct Nodo{
    int key;
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};
