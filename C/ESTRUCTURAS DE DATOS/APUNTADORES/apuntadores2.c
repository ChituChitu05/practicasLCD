//ver si una palabra es un palindromo
#include <stdio.h>
int main(){
    char cadena[50];
    char *ptr1,*ptr2;
    printf("ingrese cadena: \t");
    gets(cadena); //gets(&cadena[0]); asigna la cadena de texto desde la direccion primera posicion del arreglo.
    for(ptr2 = cadena; *ptr2 != '\0'; (ptr2)++);

    for(ptr1 = cadena, ptr2 = ptr2-1; ptr1 < ptr2; (ptr1)++ , (ptr2)--){
        if(*ptr1 != *ptr2){
            printf("no es palindromo");
            return 0;
        }
    }
    printf("si es palindromo");
    return 0;
}