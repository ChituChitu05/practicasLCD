#include <stdio.h>
#include "suma.h"
int main(){
  int a[7];
  a[0]=21;
  a[1]=23;
  a[2]=26;
  a[3]=19;
  a[4]=20;
  a[5]=21;
  a[6]=24;
  printf("la suma es %d\n",suma(a,7));
  return 0;
}

