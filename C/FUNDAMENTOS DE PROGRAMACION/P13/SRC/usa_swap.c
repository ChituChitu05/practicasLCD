#include <stdio.h>
#include "swap.h"

int main(){
  char a1,a2,a3,a4,a5,a6,a7;
  a1='H';a2=a1+1;a3=a2+1;a4=a3+1;
  a5=a4+1;a6=a5+1;a7=a6+1;
  
  printf("Orden inicial: %c %c %c %c %c %c %c\n",
         a1,a2,a3,a4,a5,a6,a7);
  swap7(&a1,&a2,&a3,&a4,&a5,&a6,&a7);
  printf("  Orden final: %c %c %c %c %c %c %c\n",
         a1,a2,a3,a4,a5,a6,a7);
  return 0;
}