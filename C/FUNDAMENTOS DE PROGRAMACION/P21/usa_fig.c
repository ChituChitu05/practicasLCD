#include "figuras.h"

int main(){
  figura f;
  char salida[1000];

  crea_fig(&f,8,8);
  fle_arr(&f);
  printf("%s\n",tostr_fig(salida,&f));
  
  crea_fig(&f,8,8);
  fle_aba(&f);
  printf("%s\n",tostr_fig(salida,&f));

  crea_fig(&f,8,8);
  fle_der(&f);
  printf("%s\n",tostr_fig(salida,&f));

  crea_fig(&f,8,8);
  fle_izq(&f);
  printf("%s\n",tostr_fig(salida,&f));

  crea_fig(&f,8,8);
  rombo(&f);
  printf("%s\n",tostr_fig(salida,&f));

  crea_fig(&f,16,4);
  printf("%d\n",dos_tri1(&f));
  printf("%s\n",tostr_fig(salida,&f));

  crea_fig(&f,16,4);
  printf("%d\n",dos_tri2(&f));
  printf("%s\n",tostr_fig(salida,&f));

  crea_fig(&f,8,8);
  printf("%d\n",dos_tri3(&f));
  printf("%s\n",tostr_fig(salida,&f));  

  crea_fig(&f,16,4);
  printf("%d\n",dos_tri4(&f));
  printf("%s\n",tostr_fig(salida,&f));  
  
  crea_fig(&f,12,6);
  printf("%d\n",dos_cuad(&f));
  printf("%s\n",tostr_fig(salida,&f));

  crea_fig(&f,8,8);
  printf("%d\n",marco(&f));
  printf("%s\n",tostr_fig(salida,&f));
  
  crea_fig(&f,8,4);
  printf("%d\n",och_acos(&f));
  printf("%s\n",tostr_fig(salida,&f));

  crea_fig(&f,12,6);
  printf("%d\n",cua_rec(&f));
  printf("%s\n",tostr_fig(salida,&f));

  crea_fig(&f,12,6);
  printf("%d\n",rom_cua(&f));
  printf("%s\n",tostr_fig(salida,&f)); 

  return 0;  
}

