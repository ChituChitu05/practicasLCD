//mcd
#include <stdio.h>

int mcd(int a, int b){
    if(a == 0 && b==0) return 0;

    if(a>=b && a%b != 0) return a-mcd(a-b,a);
    if(b>=a && b%a != 0) return b-mcd(a,b-a);
}

int main(){
    int a,b;
    a = 20;
    b = 25;
    printf("MCD(%d,%d)= %d",a,b,mcd(a,b));
}