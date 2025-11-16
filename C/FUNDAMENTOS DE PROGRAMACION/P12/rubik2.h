#ifndef _RUBIK2_H_
#define _RUBIK2_H_
/***************************************************************
                 IMPLEMENTACION CUBO RUBIK 2x2
***************************************************************/

#include <stdio.h>
#include <string.h>

#include "error.h"
/***************************************************************
        D E F I N I C I O N    D E    C O S N T A N T E S
***************************************************************/

#define NUM_PIEZAS    8       /*Número de piezas del cubo*/
#define NUM_MOV       12      /*Total de mocimientos simulados*/
#define NUM_MOV_MEZ   20      /*Número de mocimientos máximos
                                al mezclar aleatoriamente*/
/*          C O L O R E S   D E   L A S   C A R A S           */
typedef enum {BLANCO,ROJO,AZUL,AMARILLO,MORADO,VERDE} color;

/***************************************************************
        D E F I N I C I O N    D E    T I P O S
***************************************************************/

/*              P I E Z A    D E    E S Q U I N A S           */
typedef struct{
  color l_x;    /*Color del lado X de la exquina*/
  color l_y;    /*Color del lado Y de la exquina*/
  color l_z;    /*Color del lado Z de la exquina*/
}esquina;

/*                      C U B O    D E    2 X 2               */
/* Posiciones del 0 al 3 representan las esquinas superiores  */
/* Posiciones del 4 al 7 representan las esquinas inferiores  */
typedef struct{
  esquina piezas[NUM_PIEZAS];    /*Representa las 8 esquinas 
                                   del cubo*/
}cubo2;

/*    M o v i m i e n t o   q u e   s e   r e a l i z a       */
typedef int (*movimiento)(cubo2*);

/***************************************************************
       D E F I N I C I O N    D E    F U N C I O N E S
***************************************************************/
/*Inicializa el cubo
Recibe: Apuntador a cubo a ser inicializado
Regresa: Código de error
Observaciones: Se inicializa el cubo completamente armado*/
int   ini_cub2(cubo2* c);

/*       M o v i m i e n t o s   H o r i z o n t a l e s       */

/*Mueve la parte superior del cubo a la izquierda
Recibe: Apuntador a cubo que se aplica el movimiento
Regresa: Código de error*/
int   izq_1_cub2(cubo2* c);

/*Mueve la parte superior del cubo a la derecha
Recibe: Apuntador a cubo que se aplica el movimiento
Regresa: Código de error*/
int   der_1_cub2(cubo2* c);

/*Mueve la parte inferior del cubo a la izquierda
Recibe: Apuntador a cubo que se aplica el movimiento
Regresa: Código de error*/
int   izq_2_cub2(cubo2* c);

/*Mueve la parte inferior del cubo a la derecha
Recibe: Apuntador a cubo que se aplica el movimiento
Regresa: Código de error*/
int   der_2_cub2(cubo2* c);

/*        M o v i m i e n t o s    V e r t i c a l e s        */

/*Mueve la parte izquierda  del cubo hacia arriba
Recibe: Apuntador a cubo que se aplica el movimiento
Regresa: Código de error*/
int   ari_1_cub2(cubo2* c);

/*Mueve la parte izquierda  del cubo hacia abajo
Recibe: Apuntador a cubo que se aplica el movimiento
Regresa: Código de error*/
int   aba_1_cub2(cubo2* c);

/*Mueve la parte derecha  del cubo hacia arriba
Recibe: Apuntador a cubo que se aplica el movimiento
Regresa: Código de error*/
int   ari_2_cub2(cubo2* c);

/*Mueve la parte derecha  del cubo hacia abajo
Recibe: Apuntador a cubo que se aplica el movimiento
Regresa: Código de error*/
int   aba_2_cub2(cubo2* c);

/*           M o v i m i e n t o s    de   R e l o j          */

/*Mueve la parte de enfrente del cubo hacia la derecha
Recibe: Apuntador a cubo que se aplica el movimiento
Regresa: Código de error*/
int   reld_1_cub2(cubo2* c);

/*Mueve la parte de enfrente del cubo hacia la izquierda
Recibe: Apuntador a cubo que se aplica el movimiento
Regresa: Código de error*/
int   reli_1_cub2(cubo2* c);

/*Mueve la parte de atras del cubo hacia la derecha
Recibe: Apuntador a cubo que se aplica el movimiento
Regresa: Código de error*/
int   reld_2_cub2(cubo2* c);

/*Mueve la parte de atras del cubo hacia la izquierda
Recibe: Apuntador a cubo que se aplica el movimiento
Regresa: Código de error*/
int   reli_2_cub2(cubo2* c);

/*         M o v i m i e n t o s   C o m b i n a d o s        */

/*Mezcla el cubo haciendo movimientos aleatorios. El número de 
movimientos a realizar se determina con un número al azar entre
o y NUM_MOV_MEZ-1. 
Recibe: Apuntador a cubo al que se aplica el movimiento
        Número entero que se utiliza como semilla de srand para
           inicializar el generador de números aleatorios
Regresa: Código de error*/
int   mezcl_cub2(cubo2* c,int ale);

/*           C o n v e r i t r     a    c a d e n a           */
/*Convierte la representación de un cubo en una cadena que se 
 describe el cubo de forma plana. 
 
       Am Am
       Am Am
 Ro Ro Ve Ve Mo Mo Az Az
 Ro Ro Ve Ve Mo Mo Az Az
       Bl Bl
       Bl Bl
       
Am: Amarlillo
Ro: Rojo
Ve: Verde
Mo: Morado
Az: Azul
Bl: Blanco
Recibe: Apuntador a cadena que debe tener al menos 150 
            caracteres de espacio.
        Apuntador a cubo será convertido a cadena
Regresa: Código de error*/
char* tostr_cub2(char* sal,const cubo2* a);
#endif