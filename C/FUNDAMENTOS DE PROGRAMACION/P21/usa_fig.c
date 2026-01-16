#include "figuras.h"

int main(){
  figura f;
  char salida[1000];
  crea_fig(&f,24,6);
  printf("%d\n",camion(&f));
  printf("%s\n",tostr_fig(salida,&f));
  


  return 0;  
}



