#include "figuras.h"

/*Inicializa una figura con un ancho y alto dado*/
int crea_fig(figura *f, int anc, int alt)
{
  if (!ES_VAL(f))
    return AP_INV;
  if (!(anc > 1 && alt > 1))
    return DIM_INV;
  if (!(anc * alt < TAM_MAX))
    return MEM_INS;

  strcpy(f->sal, "");
  f->anc = anc;
  f->alt = alt;

  return OK;
}

/*Convierte una figura en cadena para mostrarlo en pantalla*/
char *tostr_fig(char *sal, const figura *f)
{
  if (!ES_VAL(f))
    strcpy(sal, "NULL");
  else
    strcpy(sal, f->sal);
  return sal;
}

/*Regresa el ancho*/
int getanc_fig(const figura *f)
{
  return f->anc;
}

/*Regresa el largo*/
int getalt_fig(const figura *f)
{
  return f->alt;
}

/* Modifica el largo */
int setalt_fig(figura *f, int alt)
{
  if (!ES_VAL(f))
    return AP_INV;
  f->alt = alt;
  return OK;
}

/* Modifica el ancho */
int etanc_fig(figura *f, int anc)
{
  if (!ES_VAL(f))
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

int fle_arr(figura* f){
  if (!ES_VAL(f))
    return AP_INV;
  if (f->alt < 4  || f->anc < 4)
    return DIM_INV;
  int i,j,k;

  for(i=0; i <= f->alt/2; ++i){
    for(j=0; j < f->anc - i; ++j)
      strcat(f->sal, " ");
    for(k=0; k < 2*i -1; ++k)
      strcat(f->sal, "*");
    strcat(f->sal, "\n");
  }
  for(i=f->alt/2; i <= f->alt; ++i){
    for(j=0; j < f->anc- f->anc/4 ; ++j)
      strcat(f->sal, " ");
    for(k=0; k < 2*(f->anc)/4 -1; ++k)
      strcat(f->sal, "*");
    strcat(f->sal, "\n");
  }
  return OK; 
}

int fle_aba(figura* f){
  if (!ES_VAL(f))
    return AP_INV;
  if (f->alt < 4  || f->anc < 4)
    return DIM_INV;
  int i,j,k;

  for(i=f->alt; i > f->alt/2; --i){
    for(j=0; j < f->anc- f->anc/4 ; ++j)
      strcat(f->sal, " ");
    for(k=0; k < 2*(f->anc)/4 -1; ++k)
      strcat(f->sal, "*");
    strcat(f->sal, "\n");
  }
  for(i=f->alt/2; i >= 0; --i){
    for(j=0; j < f->anc - i; ++j)
      strcat(f->sal, " ");
    for(k=0; k < 2*i -1; ++k)
      strcat(f->sal, "*");
    strcat(f->sal, "\n");
  }

  return OK; 
}

int fle_der(figura* f){
  if (!ES_VAL(f))
    return AP_INV;
  if (f->alt < 4  || f->anc < 4)
    return DIM_INV;

  int i,j,k;
  for(i = 0; i <=  f->alt;++i){
    for(j = 0; j < getanc_fig(f)/2;++j){
      if(i > (getalt_fig(f)/4)  && i < 3*(getalt_fig(f)/4))
        strcat(f->sal, "*");
      else
        strcat(f->sal, " ");
    }
      
    if(i < getalt_fig(f) /2 ){
      for(k = 0; k < i ;++k)
        strcat(f->sal, "*");
    }else{
      for(k = getalt_fig(f)-i ; k > 0;--k)
        strcat(f->sal, "*");
    }
      
    
     strcat(f->sal, "\n");
  }
 return OK;
}
int fle_izq(figura* f){
  if (!ES_VAL(f))
    return AP_INV;
  if (f->alt < 4  || f->anc < 4)
    return DIM_INV;

  int i,j,k;
  for(i = f->alt; i >= 0 ;--i){
    if(i >  getalt_fig(f)/2){
        for(k = 0; k < i - getanc_fig(f)/2; ++k){
          strcat(f->sal, " ");
        }
        for(k = 0; k < getanc_fig(f) - i ; ++k){
          strcat(f->sal, "*");
        }
    }else{
        for(k = 0; k < getanc_fig(f)/2 - i ; ++k){
          strcat(f->sal, " ");
        }
                for(k = 0; k < i  ; ++k){
          strcat(f->sal, "*");
        }
    }

    
    for(j = 0; j < getanc_fig(f)/2;++j){
      
      if(i > (getalt_fig(f)/4)  && i < 3*(getalt_fig(f)/4))
        strcat(f->sal, "*");
      else
        strcat(f->sal, " ");
    }


    strcat(f->sal, "\n");
  }
 return OK;
}

int rombo(figura*f){
  if (!ES_VAL(f))
    return AP_INV;
  if (f->alt < 3  || f->anc < 3)
    return DIM_INV;

  int i,j,k;
  for(i = 0; i < getalt_fig(f)/2;++i){
    for(j = 0;j < getanc_fig(f)/2 - i; ++j){
      strcat(f->sal, " "); 
    }
    for(k = 0;k < i + 1; ++k){
      strcat(f->sal, "*"); 
    }
    for(k = 0;k < i ; ++k){
      strcat(f->sal, "*"); 
    }
    strcat(f->sal, "\n");
  }

  for (i = getalt_fig(f)/2 ; i < getanc_fig(f) + 1;++i){
    for(j = 0;j < i - getanc_fig(f)/2 ; ++j){
      strcat(f->sal, " "); 
    }
    for(j = i - getanc_fig(f)/2;j < getanc_fig(f)/2 ; ++j){
      strcat(f->sal, "*"); 
    }
    for(j = i;j < getanc_fig(f) +1 ; ++j){
      strcat(f->sal, "*"); 
    }
    strcat(f->sal, "\n");
  }
  return OK;
}


int dos_tri1(figura* f){
  if (!ES_VAL(f))
    return AP_INV;


  if (f->alt < 2 || f->anc != getalt_fig(f) * 4)
    return DIM_INV;

  int i,j;

  for(i = 0; i < f->alt;++i){
    for(j = 0; j < getanc_fig(f)/4 - i ;++j)
      strcat(f->sal, " "); 
    for(j = 0; j < 2*i +1 ;++j)
      strcat(f->sal, "*");
    for(j = i +1 ; j <  getanc_fig(f)/2 - i  ;++j)
      strcat(f->sal, " ");
    for(j = 0; j < 2*i +1 ;++j)
      strcat(f->sal, "*");

    strcat(f->sal, "\n");
  }

  return OK;
}

int dos_tri2(figura* f){
  if (!ES_VAL(f))
    return AP_INV;

  if (f->alt < 2 || f->anc != getalt_fig(f) * 4)
    return DIM_INV;

  int i,j;

  for(i = 0; i < f->alt;++i){
    for(j = 0; j <  i  ;++j)
      strcat(f->sal, " ");
    for(j = 1; j < getanc_fig(f)/2 - 2*i ;++j)
      strcat(f->sal, "*"); 
    for(j = 0; j < 2*i +1 ;++j)
      strcat(f->sal, " ");
    for(j = i +1 ; j <  getanc_fig(f)/2 - i  ;++j)
      strcat(f->sal, "*");


    strcat(f->sal, "\n");
  }
  return OK;
}

int dos_tri3(figura* f){
  if (!ES_VAL(f))
    return AP_INV;

  if (f->alt < 3 || f->anc < 3)
    return DIM_INV;

  int i,j;

  for(i = 0; i < getalt_fig(f)/2 -1;++i){
    for(j = 0; j <  i+1  ;++j)
      strcat(f->sal, "*");
    for(j = 0; j < getanc_fig(f)/2 - 2*i +1;++j)
      strcat(f->sal, " ");
    for(j = 0 ; j <  i +1;++j)
      strcat(f->sal, "*");

    strcat(f->sal, "\n");
  }
  for(j = 0; j < getanc_fig(f)-1;++j){
    strcat(f->sal, "*");
  }
  strcat(f->sal, "\n");
  for(i = getalt_fig(f)/2 +1 ; i <  getalt_fig(f);++i){
    for(j = getanc_fig(f)-i; j >  0  ;--j)
      strcat(f->sal, "*");
    for(j = 0; j <  2*i  - getanc_fig(f)-1;++j)
      strcat(f->sal, " ");
    for(j = getanc_fig(f)-i; j >  0  ;--j)
      strcat(f->sal, "*");

    strcat(f->sal, "\n");
  }
  return OK;
}

int dos_tri3(figura* f){
  if (!ES_VAL(f))
    return AP_INV;

  if (f->alt < 3 || f->anc < getalt_fig(f)*2)
    return DIM_INV;

  int i,j;
  for (i=0; i < f->alt,++i){
    
  }
 
  return OK;
}