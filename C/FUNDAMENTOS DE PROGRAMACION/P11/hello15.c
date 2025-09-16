#include <stdio.h>
int main(){
    char men1[] = "Hola ";
    char men2[] = " todos";
    printf("%s%c%s\n", men1, men2[3] - 3, men2);
    return 0;
}
