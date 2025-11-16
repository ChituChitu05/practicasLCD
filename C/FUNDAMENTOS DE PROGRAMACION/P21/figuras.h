#ifndef FIGURAS_H
#define FIGURAS_H

#include <stdio.h>
#include <string.h>
/*Macros*/
#define ES_VAL(AP)        ((AP)!=NULL)
/*Errores*/
#define  OK               0  /*No hay error*/
#define  MEM_INS          1  /*Memoria insuficiente*/
#define  AP_INV           2  /*Apuntador nulo*/
#define  DIM_INV          3  /*Dimensión de figura no valida*/

#define TAM_MAX           10000/*Máximo tamaño de figura*/
#define TAM_AUX           1000 /* Cadena auxiliar*/

typedef struct {
  char sal[TAM_MAX];
  int anc;                     /*Dimensiones de la imágen*/
  int alt;
} figura;

/*Crea una figura, de tamaño y ancho dado*/
int crea_fig(figura*, int, int);

/*Convierte una figura en una cadena*/
char* tostr_fig(char*, const figura*);

/*Obtiene y modifica el tamaño de la figuar*/
int getanc_fig(const figura*);
int getalt_fig(const figura*);
int setalt_fig(figura*, int);
int setanc_fig(figura*, int);

/****************************************************************
                  Figuras que se construyen
/***************************************************************/
/*Triangulo rectangulo similar a:
*
**
****
*/
int fig_tri1(figura*);






#endif
