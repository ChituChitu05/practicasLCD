//contar caracteres de una cadena con apuntadores
#include <stdio.h>
int longCad(char*);
int main(){
    char *cad[50];
    gets(cad);
    printf("La longitud de la cadena es: %d", longCad(cad));
    return 0;
}

int longCad(char * ptr1){
    char *ptr2;
    for(ptr2 = ptr1; *ptr2 != '\0';(ptr2)++); //'\n' para linux
    return ((int)(ptr2 - ptr1));
} 