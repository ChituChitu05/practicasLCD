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

int fle_arr(figura* f){
  if (!ES_VAL(f))
    return AP_INV;
  if (f->alt < 4  || f->anc < 4)
    return DIM_INV;
  int i,j,k;

  strcpy(f->sal,"");
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
  strcpy(f->sal,"");
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
  strcpy(f->sal,"");
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
  strcpy(f->sal,"");
  for(i = f->alt; i >= 0 ;--i){
    if(i >  getalt_fig(f)/2){
        for(k = 0; k < i - getanc_fig(f)/2; ++k)
          strcat(f->sal, " ");
        for(k = 0; k < getanc_fig(f) - i ; ++k)
          strcat(f->sal, "*");
    }else{
        for(k = 0; k < getanc_fig(f)/2 - i ; ++k)
          strcat(f->sal, " ");
        
        for(k = 0; k < i  ; ++k)
          strcat(f->sal, "*");
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
  strcpy(f->sal,"");
  for(i = 0; i < getalt_fig(f)/2;++i){
    for(j = 0;j < getanc_fig(f)/2 - i; ++j)
      strcat(f->sal, " "); 
    
    for(k = 0;k < i + 1; ++k)
      strcat(f->sal, "*"); 
    
    for(k = 0;k < i ; ++k)
      strcat(f->sal, "*"); 
    
    strcat(f->sal, "\n");
  }

  for (i = getalt_fig(f)/2 ; i < getanc_fig(f) + 1;++i){
    for(j = 0;j < i - getanc_fig(f)/2 ; ++j)
      strcat(f->sal, " "); 
    
    for(j = i - getanc_fig(f)/2;j < getanc_fig(f)/2 ; ++j)
      strcat(f->sal, "*"); 
    
    for(j = i;j < getanc_fig(f) +1 ; ++j)
      strcat(f->sal, "*"); 
    
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
  strcpy(f->sal,"");

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
  strcpy(f->sal,"");

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
  strcpy(f->sal,"");

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

int dos_tri4(figura* f){
  if (!ES_VAL(f))
    return AP_INV;

  if (f->alt < 3 || f->anc < getalt_fig(f)*4)
    return DIM_INV;

  int i,j;
  strcpy(f->sal,"");
  for (i = 0; i < f->alt;++i){
    for(j = 0 ; j < i;++j)
      strcat(f->sal, " ");
    for(j = 0 ; j < (getanc_fig(f)/2) - 2*i -1;++j)
      strcat(f->sal, "*");
        for(j = 0 ; j < getanc_fig(f)/2 - (getanc_fig(f)/4) -1;++j)
      strcat(f->sal, " ");
    for(j = 0 ; j <  2*i +1;++j)
      strcat(f->sal, "*");
    strcat(f->sal, "\n");
  }
 
  return OK;
}

int dos_cuad(figura*f){
  if (!ES_VAL(f))
    return AP_INV;

  if (f->alt < 2 || f->anc < getalt_fig(f)*2)
    return DIM_INV;
  
  int i,j;
  strcpy(f->sal,"");
  for(i = 0; i < getalt_fig(f)/2 ; ++i){
    for(j = 0; j < getanc_fig(f)/2; ++j)
      strcat(f->sal, " ");
    
    for(j = getanc_fig(f)/2; j < getanc_fig(f); ++j)
      strcat(f->sal, "*");
    
    strcat(f->sal, "\n");
  }

  for(i = 0; i < getalt_fig(f)/4 -1; ++i){
    for(j = 0; j < getanc_fig(f)/2 ; ++j){
      strcat(f->sal, " ");
    }
    for(j = getanc_fig(f)/2; j < getanc_fig(f); ++j){
      strcat(f->sal, "*");
    }
    strcat(f->sal, "\n");
  }

  for(i = getalt_fig(f)/4 +1; i <  getalt_fig(f); ++i){
    for(j = 0; j < getanc_fig(f)/3 ; ++j){
      strcat(f->sal, "*");
    }
    for(j = getanc_fig(f)/3; j < getanc_fig(f)/2 ; ++j){
      strcat(f->sal, " ");
    }
    for(j = getanc_fig(f)/2; j < getanc_fig(f); ++j){
      strcat(f->sal, "*");
    }
    strcat(f->sal, "\n");
  }
  return OK;
}

int marco(figura*f){
  if (!ES_VAL(f))
    return AP_INV;

  if (f->alt < 3 || f->anc < 3)
    return DIM_INV;

  int i,j;
  strcpy(f->sal,"");

  for(i = 0; i<round(getalt_fig(f)/4.0); ++i){
    for(j= 0; j < getanc_fig(f);++j)
      strcat(f->sal, "*");
    strcat(f->sal, "\n");
  }
  for(i = round(getalt_fig(f)/4.0); i < round(3*(getalt_fig(f)/4.0)); ++i){
    for(j = 0; j < round(getalt_fig(f)/4.0);++j){
      strcat(f->sal, "*");
    }
    for(j = round(getalt_fig(f)/4.0); j <  round(3*getalt_fig(f)/4.0) ;++j){
      strcat(f->sal, " ");
    }
    for(j =  round(3* getalt_fig(f)/4.0) ; j < getalt_fig(f)  ;++j){
      strcat(f->sal, "*");
    }
    strcat(f->sal, "\n");
  }
  for(i = round(3*(getalt_fig(f)/4.0)); i < getalt_fig(f); ++i){
    for(j = 0; j < getanc_fig(f);++j)
      strcat(f->sal, "*");
  
  strcat(f->sal, "\n");
  }  
  return OK;
}

int och_acos(figura* f){
  if (!ES_VAL(f))
    return AP_INV;

  if (f->alt < 3 || f->anc < 2*(getalt_fig(f)))
    return DIM_INV;

  int i,j;
  strcpy(f->sal,"");

  for (j = 0; j < 2; ++j) {
    strcat(f->sal, " ");
    for (int k = 1; k < getanc_fig(f) / 2; ++k) {
        strcat(f->sal, "*");
    }
}
strcat(f->sal, "\n");
  
  for(i = 0; i < getalt_fig(f)-2; ++i){
    strcat(f->sal, "*");
     for(j=0;j < (getanc_fig(f)/2) -1; ++j){
      strcat(f->sal, " ");
     }
    strcat(f->sal, "*");
    for(j=0;j < (getanc_fig(f)/2) -1; ++j){
      strcat(f->sal, " ");
     }
    strcat(f->sal, "*");
    strcat(f->sal, "\n");
  }
  for (j = 0; j < 2; ++j) {
    strcat(f->sal, " ");
    for (int k = 1; k < getanc_fig(f) / 2; ++k) {
        strcat(f->sal, "*");
    }
  }

  return OK;
}

int cua_rec(figura* f){
  if (!ES_VAL(f))
    return AP_INV;

  if (f->alt < 3 || f->anc < 2*(getalt_fig(f)))
    return DIM_INV;

  int i,j;
  strcpy(f->sal,"");



    for(j = 0; j < getanc_fig(f); ++j){
        if(j < getanc_fig(f)/2 )
            strcat(f->sal, "*");
        else if(j == getanc_fig(f)/2 )
            strcat(f->sal, " ");
        else if(j < 3*(getanc_fig(f)/4) - 1)
            strcat(f->sal, " ");
        else
            strcat(f->sal, "*");
    }
    strcat(f->sal, "\n");
    for(i = 1; i < f->alt - 1; ++i) {
        for(j = 0; j < f->anc; ++j) {
            if(j == 0 || j ==  getanc_fig(f)/2 - 1|| j == round(getanc_fig(f)/2 +1)  || j == getanc_fig(f) - 1)
                strcat(f->sal, "*");
            else
                strcat(f->sal, " ");
        }
        strcat(f->sal, "\n");
    }
    
    for(j = 0; j < getanc_fig(f); ++j){
        if(j < getanc_fig(f)/2 )
            strcat(f->sal, "*");
        else if(j == getanc_fig(f)/2 )
            strcat(f->sal, " ");
        else if(j < 3*(getanc_fig(f)/4) - 1)
            strcat(f->sal, " ");
        else
            strcat(f->sal, "*");
    }
  return OK;
}

int rom_cua(figura* f){
  if (!ES_VAL(f))
    return AP_INV;

  if (f->alt < 3 || f->anc < getalt_fig(f)*2)
    return DIM_INV;

  int i,j;
  strcpy(f->sal,"");
  for(i = 0; i < getalt_fig(f)/2;++i){
    for(j = 0;j < getanc_fig(f)/4 - i; ++j)
      strcat(f->sal, " "); 
    
    for(j = 0;j < (2*i) + 1; ++j)
      strcat(f->sal, "*"); 
    for(j = 0;j < getanc_fig(f)/4 -i; ++j)
      strcat(f->sal, " ");

    for(j = 0; j < getanc_fig(f)/2 ; ++j){
      if(i == 0 || i == getalt_fig(f) -1)
        strcat(f->sal, "*");
      else if(j == 0 || j == (getanc_fig(f)/2) -1)
        strcat(f->sal, "*");
      else if(j != 0 || j != (getanc_fig(f)/2) -1){
        strcat(f->sal, " ");
      }
    }
    strcat(f->sal, "\n");
  }
  for( i = 0 ; i < getalt_fig(f)/2 ;++i){
    for(j = 0;j < i  ; ++j)
      strcat(f->sal, " "); 
    for(j = 0;j < getanc_fig(f)/2 -(2*(i)); ++j)
      strcat(f->sal, "*"); 
    
    for(j = 0;j < i +1; ++j)
      strcat(f->sal, " "); 

    for(j = 0; j < getanc_fig(f)/2 ; ++j){
      if(i == getalt_fig(f)/2 -1)
        strcat(f->sal, "*");
      else if(j == 0 || j == (getanc_fig(f)/2) -1)
        strcat(f->sal, "*");
      else if(j != 0 || j != (getanc_fig(f)/2) -1){
        strcat(f->sal, " ");
      }
    }

    strcat(f->sal, "\n");
  }
  return OK;
}

int dos_casas(figura* f){
  if (!ES_VAL(f))
    return AP_INV;

  if (f->alt < 3 || f->anc < getalt_fig(f)*3)
    return DIM_INV;

  int i,j;
  strcpy(f->sal,"");


  for(i = 0; i < getalt_fig(f)/2 +1;++i){
    for(j = 0;j < getanc_fig(f)/3 - i -getanc_fig(f)/8; ++j)
      strcat(f->sal, " "); 
    
    for(j = 0;j < (2*i) + 1; ++j)
      strcat(f->sal, "*"); 
    for(j = 0;j < ((getanc_fig(f)/3 - i)*2 - getanc_fig(f)/4) ; ++j)
      strcat(f->sal, " ");

    for(j = 0;j < (2*i) + 1; ++j)
      strcat(f->sal, "*"); 
    strcat(f->sal, "\n");
  }


  for(i = 0; i < getalt_fig(f)/2;++i){
    for(j = 0; j < getanc_fig(f) ; ++j){
      if(j == getanc_fig(f)/10 || j == getanc_fig(f)/3 +1 || j == 1*getanc_fig(f)/2 +2  || j == getanc_fig(f) - getanc_fig(f)/10 -2)
        strcat(f->sal, "*");
      else
        strcat(f->sal, " ");
    }
    strcat(f->sal, "\n");
  }
  for(j = 0; j < getanc_fig(f)-1; ++j)
      strcat(f->sal, "*");
  return OK;
}

int dos_rombos_huecos(figura* f){
  if (!ES_VAL(f))
    return AP_INV;

  if (f->alt < 5 || f->anc < 2* getalt_fig(f))
    return DIM_INV;

  int i,j;
  strcpy(f->sal,"");

  for (i = 0; i < getalt_fig(f)/2; i++) {
    for (j = 0; j < getanc_fig(f)/4-i; j++)
      strcat(f->sal, " ");
    for (j = 0; j < 2*i + 1; j++) {
      if (j == 0 || j == 2*i || i == getalt_fig(f)/2 -1)
        strcat(f->sal, "*");
      else
         strcat(f->sal, " ");
     }
    for (j = 0; j < getalt_fig(f) - (2*i - 1) -1; j++){
      strcat(f->sal, " ");
    }

    for (j = 0; j < 2*i + 1; j++) {
      if (j == 0 || j == 2*i || j == i )
        strcat(f->sal, "*");
      else
         strcat(f->sal, " ");
     }
    strcat(f->sal, "\n");
  }
for( i = getalt_fig(f)/2 +1 ; i < getalt_fig(f); i++) {
    for (j = 0; j < i - getanc_fig(f)/4 +1; j++)
      strcat(f->sal, " ");
    for (j = 0; j < 2*(getalt_fig(f) - i) - 1; j++) {
      if (j == 0 || j == 2*(getalt_fig(f) - i) - 2 || i == getalt_fig(f)/2 )
        strcat(f->sal, "*");
      else
         strcat(f->sal, " ");
     }
    for (j = 0; j < (2*i - getalt_fig(f)) +2; j++){
      strcat(f->sal, " ");
    }

for( j = 0; j < 2*(getalt_fig(f) - i) - 1; j++) {
      if (j == 0 || j == 2*(getalt_fig(f) - i) - 2 || j == getalt_fig(f) - i - 1)
        strcat(f->sal, "*");
      else
         strcat(f->sal, " ");
     }
    strcat(f->sal, "\n");
  }
  return OK;
}

int letra_u(figura* f){
  if (!ES_VAL(f))
    return AP_INV;

  if (f->alt < 5 || f->anc < 10)
    return DIM_INV;

  int i,j;

  strcpy(f->sal,"");
  for (i = 0; i < getalt_fig(f); ++i) {
    if (i == 0 || i == getalt_fig(f) -1) {
      for (j = 0; j < getanc_fig(f) ; ++j)
        strcat(f->sal, "-");
    } else if (i <= getalt_fig(f) - 5) {
      for (j = 0; j < getanc_fig(f); ++j) {
        if (j == getanc_fig(f)/7  || j == getanc_fig(f)/7 + 1 || j == getanc_fig(f) - 4 || j == getanc_fig(f) - 3)
          strcat(f->sal, "*");
        else
          strcat(f->sal, "-");
      }
    } else if (i == getalt_fig(f) - 4) {
      for (j = 0; j < getanc_fig(f); ++j) {
        if ((j >= getanc_fig(f)/7 + 1 && j <= getanc_fig(f)/7 + 2) || (j >= getanc_fig(f) - 5 && j <= getanc_fig(f) - 4))
          strcat(f->sal, "*");
        else
          strcat(f->sal, "-");
      }
    } else if (i == getalt_fig(f) - 3) {
      for (j = 0; j < getanc_fig(f); ++j) {
        if (j >= getanc_fig(f)/7 + 2 && j <= getanc_fig(f) - 5)
          strcat(f->sal, "*");
        else
          strcat(f->sal, "-");
      }
    } else {
      for (j = 0; j < getanc_fig(f); ++j) {
        if (j > getanc_fig(f)/7 + 2 && j <  getanc_fig(f) -5)
          strcat(f->sal, "*");
        else
          strcat(f->sal, "-");
      }
    }
    strcat(f->sal, "\n");
  }

  return OK;
}

int letra_n(figura* f){
  if (!ES_VAL(f))  
    return AP_INV;

  if (getalt_fig(f) < 5 || getanc_fig(f) < getalt_fig(f)*2) 
    return DIM_INV;

  int i,j;
  strcpy(f->sal, "");
  for (i = 0; i < getalt_fig(f); ++i) {
    for (j = 0; j < getanc_fig(f); ++j) {
      if (i == 0 || i == getalt_fig(f) - 1) {
        strcat(f->sal, "-");
      } else if (i == 1) {
        if (j >= getanc_fig(f)/8  +2 && j < getanc_fig(f)- getanc_fig(f)/4) 
          strcat(f->sal, "*");
        else 
          strcat(f->sal, "-");
      } else if (i == 2) {
        if (j >= getanc_fig(f)/8  +1 && j < getanc_fig(f)- getanc_fig(f)/4 +1) 
          strcat(f->sal, "*");
        else 
          strcat(f->sal, "-");
      } else {
        if (j == 2 || j == 3 || j == getanc_fig(f) - 4 || j == getanc_fig(f) - 3)
          strcat(f->sal, "*");
        else
          strcat(f->sal, "-");
      }
    }
    strcat(f->sal, "\n");
  }

  return OK;
}

int letra_x(figura*f){
  if (!ES_VAL(f))  
    return AP_INV;

  if (getalt_fig(f) < 2*getanc_fig(f) || getanc_fig(f) < 3) 
    return DIM_INV;
  int i,j;
 
  strcpy(f->sal,"");
  for(i = 0; i < getalt_fig(f)/2; ++i){

    for(j = 0; j < getanc_fig(f); ++j){
      if(j == i || j == getanc_fig(f) - i -1)
        strcat(f->sal, "*");
      else
        strcat(f->sal, " ");
    }
    strcat(f->sal, "\n");
  }
  return OK;
}

int dos_triangulos_5(figura*f){
    if (!ES_VAL(f))  
      return AP_INV;
    
    if (getalt_fig(f) < 2*getanc_fig(f) || getanc_fig(f) < 3) 
       return DIM_INV;
  int i,j;
  
  strcpy(f->sal, "");

  
  for (i = 0; i < (getalt_fig(f) / 2)-1; ++i) {    

    for (j = 0; j < i + 1; ++j) 
      strcat(f->sal, "*");

    strcat(f->sal, "\n");
  }
  for(j=0; j< getalt_fig(f); ++j)
    if(j< getanc_fig(f)/2 +1 ||j> getanc_fig(f)/2 ){
      strcat(f->sal, "*");
    }else{
      strcat(f->sal, " ");
    }
  
  strcat(f->sal, "\n");  
  for (i = 1; i < (getalt_fig(f) / 2)+1; ++i) {
    for (j = 0; j < getalt_fig(f) / 2 -i -1; ++j) 
      strcat(f->sal, " ");
    for (j = 0; j < 2*i + 1;  ++j) 
      strcat(f->sal, " ");
    for (j = 0; j < getalt_fig(f) / 2 -i; ++j) 
      strcat(f->sal, "*");
    strcat(f->sal, "\n");
  }
  return OK;
}

int dos_triangulos_6(figura*f){
    if (!ES_VAL(f))  
      return AP_INV;
    if (getalt_fig(f) < 3 || getanc_fig(f) < 3) 
      return DIM_INV;
  int i,j;
  
  strcpy(f->sal, "");
  for (i = 0; i < (getalt_fig(f) / 2)-2; ++i) {    

    for (j = 0; j < (getalt_fig(f) / 2) - 2*i ; ++j) 
      strcat(f->sal, "*");

    strcat(f->sal, "\n");
  }
  for(j=0; j < getalt_fig(f); ++j)
    if(j == 0 ||j == getanc_fig(f)-1){
      strcat(f->sal, "*");
    }else{
      strcat(f->sal, " ");
    }
  
  strcat(f->sal, "\n");  
  for (i = 1; i < (getalt_fig(f) / 2)-1; ++i) {
    for (j = 0; j < getalt_fig(f)  -i -1; ++j) 
      strcat(f->sal, " ");

    for (j = 0; j < i +1; ++j) 
      strcat(f->sal, "*");
    strcat(f->sal, "\n");
  }
  return OK;
}

int letra_v(figura*f){
  if (!ES_VAL(f))  
    return AP_INV;
  if (getalt_fig(f) < 3 || getanc_fig(f) < 3) 
    return DIM_INV;
 
  int i,j;
  strcpy(f->sal, "");

 
  for (i = 0; i < getanc_fig(f) / 2 ; ++i) {
    for (j = 0; j < i + 1; ++j)
      strcat(f->sal, "*");
    for (j = 0; j < getanc_fig(f) - 2*i ;  ++j)
      strcat(f->sal, " ");
    for (j = 0; j < i + 1; ++j)
      strcat(f->sal, "*");
    strcat(f->sal, "\n");
  }

  for (i = getanc_fig(f) / 2; i < getalt_fig(f); ++i) {
 
    for (j = 0; j < i - (getanc_fig(f) / 2 - 1); ++j) 
      strcat(f->sal, " ");
    for (j = 0; j < 2*(getanc_fig(f) - i); ++j) 
      strcat(f->sal, "*");
    strcat(f->sal, "\n");
  }
  
  return OK;
}

int letra_a(figura*f){
  if (!ES_VAL(f))  
    return AP_INV;
  if (getalt_fig(f) < 3 || getanc_fig(f) < 3) 
    return DIM_INV;
 
  int i,j;
  strcpy(f->sal, "");
   
  for(i = 0; i < getalt_fig(f)/3 + 1; ++i){
    for(j = 0; j < getanc_fig(f)/2 - i -1; ++j)
      strcat(f->sal, " ");
    for(j = 0; j < 2*i +1; ++j)
      strcat(f->sal, "*");
    for(j = 0; j < getanc_fig(f)/2 - i -1; ++j)
      strcat(f->sal, " ");
    strcat(f->sal, "\n");
  }
  for(i = getalt_fig(f)/3 +1; i < 2*getalt_fig(f)/3; ++i){
    for(j = 0; j < getanc_fig(f)/2-i +2; ++j){
      strcat(f->sal, "*");
    }
    for(j = 0; j < 2*i -getanc_fig(f)/2 -1; ++j){
      strcat(f->sal, " ");
    }
    for(j = 0; j < getanc_fig(f)/2-i +2; ++j){
      strcat(f->sal, "*");
    }
    strcat(f->sal, "\n");
  }
  for (i = 2*getalt_fig(f)/3; i < getalt_fig(f) -1; ++i) {
    for (j = 0; j < getanc_fig(f) -1; ++j) {
      strcat(f->sal, "*");
    }
    strcat(f->sal, "\n");
  }
  for(j = 0; j < getanc_fig(f)-1; ++j){
    if(j == 0 || j == getanc_fig(f) -2)
      strcat(f->sal, "*");
    else
      strcat(f->sal, " ");
  }
  return OK;
}

int rect_iden(figura*f){
  if (!ES_VAL(f))  
    return AP_INV;
  if (getalt_fig(f) < 3 || getanc_fig(f) < 3) 
    return DIM_INV;
  int i,j;
  strcpy(f->sal, "");
    for (int i = 0; i < getalt_fig(f)-1; i++) {
        for (int j = 0; j < getanc_fig(f)-1; j++) {
            if (j == 0 ) 
              strcat(f->sal, "*");
            else if (i == getanc_fig(f)-2)
              strcat(f->sal, "*");
            else if(j == getanc_fig(f)-i -2)
              strcat(f->sal, "+");
            else
              strcat(f->sal, " ");
        }
        strcat(f->sal, "\n");
    }
  return OK;
}
/*
señal de estacionamiento
*/

int casa(figura*f){

  if (!ES_VAL(f))  
    return AP_INV;
  if (getalt_fig(f) < 5 || getanc_fig(f) < getalt_fig(f)+4) 
    return DIM_INV;
  int i,j;
  strcpy(f->sal, "");
  for(i = 0; i < getalt_fig(f) /2; ++i){
    for(j = 0; j < getanc_fig(f)/2 - i -3; ++j)
      strcat(f->sal, " ");
    for(j = 0; j < 2*i +7; ++j)
      if(i == 0||j == 0 || j == 2*i +6)
        strcat(f->sal, "*");
      else
        strcat(f->sal, " ");
    strcat(f->sal, "\n");
  }

  for(i = 0; i < getalt_fig(f) /2 +1; ++i){
    for(j = 0; j < getanc_fig(f); ++j)
      if(i == 0 || j == 0 || j == getanc_fig(f)-1 || i == getalt_fig(f)/2)
        strcat(f->sal, "*");
      else
        strcat(f->sal, " ");
    
    strcat(f->sal, "\n");
  }
  return OK;
}

int barco(figura*f){
  if (!ES_VAL(f))  
    return AP_INV;
  if (getalt_fig(f) < 5 || getanc_fig(f) < getalt_fig(f)+4) 
    return DIM_INV;
  int i,j;
  strcpy(f->sal, "");
  for(i = 0; i < getanc_fig(f)/2 -1; ++i){
    for(j = 0; j < getanc_fig(f)/2 - i; ++j)
      strcat(f->sal, " ");
    for(j = 0; j < 2*i +2; ++j)
      strcat(f->sal, "*");
    strcat(f->sal, "\n");
  }
  for(i = 0; i < getalt_fig(f)/3; ++i){
    for(j = 0; j < getanc_fig(f)/2 ; ++j)
      strcat(f->sal, " ");
    strcat(f->sal, "*");
    strcat(f->sal, "\n");
  }
  for (i = 0; i < getanc_fig(f)/3-1; ++i) {
    for(j=0; j<i; ++j)
      strcat(f->sal, " ");
    for(j = 0; j < getanc_fig(f)-2*i +1; ++j)
      strcat(f->sal, "*");
    strcat(f->sal, "\n");
  }
  
  return OK;
}

int ipn(figura*f){


  if (!ES_VAL(f))  
    return AP_INV;
  if (getalt_fig(f) < 6 || getanc_fig(f) < getalt_fig(f)*2) 
    return DIM_INV;
  int i,j; 
  strcpy(f->sal, "");         
               

for (i = 0; i < getalt_fig(f); i++) {
    for (j = 0; j < getanc_fig(f) / 3; j++) {
        int mid = getanc_fig(f) / 6;
        if (i == 0 || i == getalt_fig(f)-1)
            strcat(f->sal, "*");
        else if (j == mid)
            strcat(f->sal, "*");
        else
            strcat(f->sal, " ");
    }
    strcat(f->sal, " ");

    for (j = 0; j < getanc_fig(f) / 3; j++) {
        

        if (j == 0)
            strcat(f->sal, "*");
        else if (i == 0 && j < getanc_fig(f) / 3 - 1)
            strcat(f->sal, "*");
        else if (i == getalt_fig(f) / 2 && j < getanc_fig(f) / 3 - 1)
            strcat(f->sal, "*");
        else if (i < getalt_fig(f) / 2 && j == getanc_fig(f) / 3 - 1)
            strcat(f->sal, "*");
        else
            strcat(f->sal, " ");
    }
    strcat(f->sal, " ");


    for (j = 0; j < getanc_fig(f) / 3; j++) {


        if (j == 0)
            strcat(f->sal, "*");             
        else if (j == getanc_fig(f) / 3 - 1)
            strcat(f->sal, "*");             
        else if (j == i * (getanc_fig(f) / 3 - 1))
            strcat(f->sal, "*");               
        else
            strcat(f->sal, " ");
    }

    strcat(f->sal, "\n");
}

return OK;
}


int may_que(figura* f){
  if (!ES_VAL(f))
    return AP_INV;
  if (f->alt < 4  || f->anc < 4)
    return DIM_INV;
  int i,j;
  strcpy(f->sal,"");

    
for (i = 0; i < getalt_fig(f)/2; ++i) {
    for (j = 0; j < 2*i; ++j)
        strcat(f->sal, " ");
    for (j = 0; j < getanc_fig(f)/2 - i; ++j)
        strcat(f->sal, "*");
    strcat(f->sal, "\n");
}

for (i = getalt_fig(f)/2 - 1; i >= 0; --i) {
    for (j = 0; j < 2*i; ++j)
        strcat(f->sal, " ");
    for (j = 0; j < getanc_fig(f)/2 - i; ++j)
        strcat(f->sal, "*");
    strcat(f->sal, "\n");
}
  return OK;
}

int men_que(figura* f){
  if (!ES_VAL(f))
    return AP_INV;
  if (f->alt < 4  || f->anc < 4)
    return DIM_INV;
  int i,j;
  strcpy(f->sal,"");
 
for (i = 0; i < getalt_fig(f)/2; ++i) {
    for (j = 0; j < getanc_fig(f)/2 - 2*i +2; ++j)
        strcat(f->sal, " ");
    for (j = 0; j < getanc_fig(f)/2 - i; ++j)
        strcat(f->sal, "*");

    strcat(f->sal, "\n");
}

for (i = getalt_fig(f)/2 - 1; i >= 0; --i) {
    for (j = 0; j < getanc_fig(f)/2 - 2*i +2; ++j)
        strcat(f->sal, " ");
    for (j = 0; j < getanc_fig(f)/2 - i; ++j)
        strcat(f->sal, "*");


    strcat(f->sal, "\n");
}
  return OK;
}

int sen_est(figura *f)
{
  if (!ES_VAL(f))
    return AP_INV;
  if (f->anc < 10 || f->alt < 13)
    return DIM_INV;

  int i,j;
  strcpy(f->sal,"");
  for(i = 0; i < (f->alt*2)/3; ++i){

    for(j = 0; j < f->anc; ++j){
      if ((i == 0 && j > 0 && j < f->anc-1) ||
          (i == (f->alt*2)/3 - 1 && j > 0 && j < f->anc-1) ||
          (j == 0 && i > 0 && i < (f->alt*2)/3 - 1) ||
          (j == f->anc - 1 && i > 0 && i < (f->alt*2)/3 - 1))
      {
        strcat(f->sal,"*");
      }

      else {
        if (j == f->anc/5){
          strcat(f->sal,"*");
        }else if ((i == ((f->alt*2)/3)/6     && j >= f->anc/5 && j <= (f->anc*4)/5 - 1) ||
                 (i == ((f->alt*2)/3)/2     && j >= f->anc/5 && j <= (f->anc*4)/5 - 1) ||
                 (i == (((f->alt*2)/3)*5)/6 && j >= f->anc/5 && j <= (f->anc*4)/5 - 1))
        {
          strcat(f->sal,"*");
        }else {
          strcat(f->sal," ");
        }
      }
    }

    strcat(f->sal,"\n");
  }

  for(i = 0; i < f->alt - (f->alt*2)/3; ++i){
    for(j = 0; j < f->anc; ++j){
      if (j == f->anc/2)
        strcat(f->sal,"*");
      else
        strcat(f->sal," ");
    }
    strcat(f->sal,"\n");
  }

  return OK;
}

int dif_0(figura* f){
  if (!ES_VAL(f))
    return AP_INV;
  if (f->alt < 8 || f->anc < 16)
    return DIM_INV;

  int i,j;
  strcpy(f->sal,"");
  strcpy(f->sal,"");
  for(i=0;i<f->alt+1;i++){
    if(i<f->alt/2){
      for(j=0;j<f->alt/2;j++)
        strcat(f->sal,"*");
    }
    else if(i<f->alt-f->alt/2+2){
      for(j=0;j<f->alt/8;j++)
        strcat(f->sal," ");
      for(j=0;j<f->alt/4;j++)
        strcat(f->sal,"*");
      for(j=0;j<f->alt/8;j++)
        strcat(f->sal," ");
    }
    else if(i<f->alt-f->alt/4+1){
      for(j=0;j<f->alt/2;j++)
        strcat(f->sal," ");
    }
    else{
      for(j=0;j<f->alt/2;j++)
        strcat(f->sal,"*");
    }
    
    for(j=0;j<3;j++)
      strcat(f->sal," ");
    
    if(i==0||i+1==f->alt+1){
      strcat(f->sal," ");
      for(j=0;j<f->alt;j++)
      strcat(f->sal,"*");
    }
    else{
      for(j=0;j<f->alt/3;j++)
        strcat(f->sal,"*");
      if(i>(f->alt*2)/3+1)
        for(j=0;j<(f->alt*2)/3+1;j++)
          strcat(f->sal," ");
      else{
        for(j=2;j<i;j++)
          strcat(f->sal," ");
      }
      if(i==1)
        strcat(f->sal,"*");
      else if(i+1==f->alt-2){
        strcat(f->sal,"*");
        strcat(f->sal,"*");
      }
      else if(i>(f->alt*2)/3+1){
        strcat(f->sal,"");
      }
      else{
        strcat(f->sal,"*");
        strcat(f->sal,"*");
      }
      for(j=i;j<f->alt-f->alt/3;j++)
        strcat(f->sal," ");
      for(j=0;j<f->alt/3;j++)
        strcat(f->sal,"*");
    }
    strcat(f->sal,"\n");
  }
  return OK;
}


int sen_no_est(figura *f)
{
  if (!ES_VAL(f))
    return AP_INV;
  if (f->anc < 10 || f->alt < 13)
    return DIM_INV;

  int i,j;
  strcpy(f->sal,"");

  for(i = 0; i < (f->alt*2)/3; ++i){
    for(j = 0; j < f->anc; ++j){
      if ((i == 0 && j > 0 && j < f->anc-1) ||
          (i == (f->alt*2)/3 - 1 && j > 0 && j < f->anc-1) ||
          (j == 0 && i > 0 && i < (f->alt*2)/3 - 1) ||
          (j == f->anc - 1 && i > 0 && i < (f->alt*2)/3 - 1))
      {
        strcat(f->sal,"*");
      }
      else {
        if (i > 0 && i < (f->alt*2)/3 - 1 && 
            j > 0 && j < f->anc - 1) {

          int calc_val = (i - 1) * (f->anc - 3) - ((f->anc - 2 - j) - 1) * ((f->alt*2)/3 - 3);
          

          if (calc_val >= -2 && calc_val <= 2) {
            strcat(f->sal,"//");
            continue; 
          }
        }
        
        if (j == f->anc/5){
          strcat(f->sal,"*");
        }

        else if ((i == ((f->alt*2)/3)/6     && j >= f->anc/5 && j < (f->anc*3)/4) ||
                 (i == ((f->alt*2)/3)/2     && j >= f->anc/5 && j < (f->anc*3)/4) ||
                 (i == (((f->alt*2)/3)*5)/6 && j >= f->anc/5 && j < (f->anc*3)/4))
        {
          strcat(f->sal,"*");
        }
        else {
          strcat(f->sal," ");
        }
      }
    }
    strcat(f->sal,"\n");
  }

  for(i = 0; i < f->alt - (f->alt*2)/3; ++i){
    for(j = 0; j < f->anc; ++j){
      if (j == f->anc/2)
        strcat(f->sal,"*");
      else
        strcat(f->sal," ");
    }
    strcat(f->sal,"\n");
  }

  return OK;
}

int rectangulo(figura *f)
{
  if (!ES_VAL(f))
    return AP_INV;
  if (f->anc < 15 || f->alt < 5)
    return DIM_INV;

  int i,j;
  strcpy(f->sal,"");
  
  for(i = 0; i < f->alt; ++i){
    for(j = 0; j < f->anc; ++j){
      if (i == 0 || i == f->alt - 1){
        strcat(f->sal,"*");
      }
      else {
        if (j == 0 || j == f->anc - 1){
          strcat(f->sal,"*");
        }
        else {
          strcat(f->sal," ");
        }
      }
    }
    strcat(f->sal,"\n");
  }

  return OK;
}
int camion(figura *f) {
  if (!ES_VAL(f))
    return AP_INV;
  if (f->alt < 6 || f->anc < 4*(f->alt/6))
    return DIM_INV;

  int i,j;
  strcpy(f->sal,"");
for(i=0;i<f->alt/6;i++){
    for(j=0;j<f->anc-((f->anc-1)/4);j++)
      strcat(f->sal,"*"); 
    strcat(f->sal,"\n");
  }
  for(i=0;i<f->alt/3;i++){
    strcat(f->sal,"*");
    for(j=0;j<f->anc-((f->anc-2)/3);j++)
      strcat(f->sal," ");
    strcat(f->sal,"*");
    if(i+1==f->alt/3){
      for(j=0;j<((f->anc-2)/8);j++)
        strcat(f->sal,"*");
    }   
    strcat(f->sal,"\n");
  }
  for(i=0;i<f->alt/6;i++){
    strcat(f->sal,"*");
    for(j=0;j<f->anc-((f->anc+1)/6);j++)
      strcat(f->sal," ");
    for(j=0;j<((f->anc-1)/8);j++)
      strcat(f->sal,"*");  
    strcat(f->sal,"\n");
  }
  for(i=0;i<f->alt/6;i++){
    for(j=0;j<(f->anc)/17;j++)
      strcat(f->sal,"*");
    for(j=0;j<f->anc/17;j++)
      strcat(f->sal," ");
    for(j=0;j<(f->anc+1)/6;j++)
      strcat(f->sal,"*");
    for(j=0;j<(f->anc-2)/3;j++)
      strcat(f->sal," ");
    for(j=0;j<(f->anc+1)/6;j++)
      strcat(f->sal,"*");
    for(j=0;j<(f->anc+1)/6;j++)
      strcat(f->sal," ");
    strcat(f->sal,"*");
    strcat(f->sal,"\n");
  }
  for(i=0;i<f->alt/6;i++){
    for(j=0;j<(f->anc+1)/8;j++)
      strcat(f->sal,"*");
    for(j=0;j<(f->anc)/17;j++)
      strcat(f->sal," ");
    strcat(f->sal,"O");
    for(j=0;j<(f->anc)/17;j++)
      strcat(f->sal," ");
    for(j=0;j<(f->anc-2)/3;j++)
      strcat(f->sal,"*");
    for(j=0;j<(f->anc)/17;j++)
      strcat(f->sal," ");
    strcat(f->sal,"O");
    for(j=0;j<(f->anc)/17;j++)
      strcat(f->sal," ");
    for(j=0;j<(f->anc-1)/4;j++)
      strcat(f->sal,"*");
    strcat(f->sal,"\n");
  }
  return OK;
}