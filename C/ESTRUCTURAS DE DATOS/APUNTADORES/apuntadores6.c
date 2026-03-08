//rellenar arreglo de estructuras con apuntador simple
#include <stdio.h>
struct Persona {
    char nombre[30];
    int edad;
    float alt;
    char sexo; 
};
//struct persona per1(accede con .),*ptrs(accede con ->); (instancia) 

int main(){
    struct Persona arreglo[5], *ptrs;
    for(ptrs = arreglo;ptrs < &arreglo[5];(ptrs)++){
        gets(ptrs -> nombre);
        scanf("%d", ptrs-> edad);
        scanf("%F", ptrs-> alt);
        ptrs -> sexo = getchar();
    }
    for(ptrs = arreglo;  ptrs < &arreglo[5];ptrs = ptrs + 1){

    }
    
    return 0;
}