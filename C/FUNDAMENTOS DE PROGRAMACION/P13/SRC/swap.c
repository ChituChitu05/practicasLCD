#include "swap.h"

int swap7 (char* x1,char* x2,char* x3,char* x4,char* x5,char* x6,char* x7){
  char aux;
  /*Coloca aquí tu código, sólo sentencias ejecutables*/
  /*B E A F D G C*/
  aux = *x1;
  *x1 = *x2;
  *x2 = *x5;
  *x5 = *x4;
  *x4 = *x6;
  *x6 = *x7;
  *x7 = *x3;
  *x3 = aux;




  return 0;
}
