#include "figuras.h"

/*Inicializa una figura con un ancho y alto dado*/
int crea_fig(figura* f, int anc, int alt){
  if (!ES_VAL(f))
    return AP_INV;
  if(!(anc>1 && alt>1))
    return DIM_INV;
  if(!(anc*alt<TAM_MAX))
    return MEM_INS;

  strcpy(f->sal,"");
  f->anc = anc;
  f->alt = alt; 

  return OK;
}

/*Convierte una figura en cadena para mostrarlo en pantalla*/
char* tostr_fig(char* sal, const figura* f){
  if(!ES_VAL(f))
    strcpy(sal,"NULL");
  else
    strcpy(sal,f->sal);
  return sal;
}

/*Regresa el ancho*/
int getanc_fig(const figura* f){
  return f->anc;
}

/*Regresa el largo*/
int getalt_fig(const figura* f){
  return f->anc;
}

/* Modifica el largo */
int setalt_fig(figura*f, int alt){
  if(!ES_VAL(f))
    return AP_INV;
  f->alt = alt;
  return OK;
}

/* Modifica el ancho */
int etanc_fig(figura*f, int anc){
  if(!ES_VAL(f))
    return AP_INV;
  f->anc = anc;
  return OK;

}

/*
Pinta un triangulo de tamaño fijo por alto
*
**
***
Recibe:
  figura en la que se pintará el tríangulo
Regresa:
  código de error en caso de reccibi apuntador
  nulo OK en otro caso
*/
int fig_tri1(figura* f){
  int i,j;
  if(!ES_VAL(f))
    return AP_INV;

  strcpy(f->sal,"");
  for(i=0;i<f->alt;i++){
    for(j=0;j<i;j++)
      strcat(f->sal,"*");
    strcat(f->sal,"\n");
  }
  return OK;
}


