#include "suma.h"

int suma(int* a, int n){
  int tot;
  printf("%d (%d) ",a[n-1],n);
  tot = n==1?a[0]:a[n-1]+suma(a,n-1);
  printf("{%d}\n",tot);
  return tot;
}