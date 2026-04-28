//corregir
#include <stdio.h>

int suma(int a,int b){
    if(b == 0) return 1;
    if(a == 0) return 1;
    if(a == b == 0) return 0;
    
    
    return a + suma(a,b-1);
}

int main(){
    printf("%d", suma(50,5000));
    return 0;
}