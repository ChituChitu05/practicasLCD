#include "figuras.h"

int main(){
  figura f;
  char salida[1000];

  crea_fig(&f,10,10);
  fig_tri1(&f);
  printf("%s\n",tostr_fig(salida,&f));
  return 0;  
}

