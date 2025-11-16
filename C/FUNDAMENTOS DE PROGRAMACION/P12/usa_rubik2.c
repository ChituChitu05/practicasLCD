#include <stdio.h>
/* Ejemplo de uso de las funciones     *
 *  Para representar el cubo Rubik 2x2  *
 *  Se incluye el archivo rubik2.c     */
#include "rubik2.h"

int main()
{
  char sal[500]; /*Salida del programa */
  cubo2 cub;     /*Cub representa al cubo*/
  int i;
  /* Inicializa el cubo */
  ini_cub2(&cub);
  /*cubo normal*/
  tostr_cub2(sal, &cub);
  printf("%s\n", sal);

  /* Mezcla el cubo con semilla 1*/
  mezcl_cub2(&cub,754);

  /*Conveirte el cubo a una cadena de caracteres y
    la muestra en pantalla*/
  printf("%s\n", tostr_cub2(sal, &cub));

  /*SOLUCION*/
  reld_2_cub2(&cub);
  der_1_cub2(&cub);
  der_1_cub2(&cub);
  aba_2_cub2(&cub);
  izq_2_cub2(&cub);
  ari_2_cub2(&cub);
  der_2_cub2(&cub);
    aba_2_cub2(&cub);
  izq_2_cub2(&cub);
  ari_2_cub2(&cub);
  der_2_cub2(&cub);
  printf("%s\n", tostr_cub2(sal, &cub));
  return 0;
}