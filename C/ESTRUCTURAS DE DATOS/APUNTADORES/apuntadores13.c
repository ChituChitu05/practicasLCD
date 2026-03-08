//palindromo con funciones

#include <stdio.h>
int palindromo(char*);
int main(){
    char cad[50];
    printf("ingresa cadena:\n");
    // fgets(cad,50,stdin); para linux
    gets(cad);
    if(palindromo(cad))
        printf("Es palindromo");
    else
        printf("No es palindromo");
    return 0;
}
int palindromo(char* cadena){
    char *ptr1,*ptr2;
    for(ptr2 = cadena; *ptr2 != '\0'; ptr2++);
    for(ptr1 = cadena, ptr2--; ptr1 < ptr2; ptr1++ ,ptr2 --){
        if(*ptr1 != *ptr2)
            return 0;
        
        return 1;
    }
}