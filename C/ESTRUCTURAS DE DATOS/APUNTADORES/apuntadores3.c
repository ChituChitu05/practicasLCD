//puntero doble
#include <stdio.h>

int main(){
    int a,b;
    int *ptr1;
    int **ptr2;

    a = 10;
    ptr1 = &a;
    ptr2 = &ptr1;
    b = **ptr2;

    printf("El valor %d esta en la direccion %p", b, *ptr2);

    return 0;
}
