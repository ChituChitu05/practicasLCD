# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define TAM 100


//ptrm de ptr meter, ptrs de ptr sacar
struct Cola{
    int arreglo[TAM];
    int *ptrm, *ptrs;
};

int meterCola(struct Cola *ptrC, int dato){
    *ptrC->ptrm = dato;
    ptrC->ptrm = ptrC->ptrm+1;
    return 0;

}

int sacarCola(struct Cola *ptrC){
    int dato;
    dato = *ptrC->ptrs;
    ptrC->ptrs = ptrC->ptrs + 1;
    return dato;
}

int estaColaLlena(struct Cola *ptrC){
    if(ptrC->ptrm == &ptrC->arreglo[TAM]){
        return 1;
    } else{
        return 0;
    }
}

int estaColaVacia(struct Cola *ptrC){
    if(ptrC->ptrm == ptrC->ptrs){
        return 1;
    } else{
        return 0;
    }
}

int resetearCola(struct Cola *ptrC){
    ptrC->ptrm = ptrC->arreglo;
    ptrC->ptrs = ptrC->arreglo;
}

int imprimirCola(struct Cola *ptrC){
    int *aux = ptrC->ptrs;
    for (aux; aux < ptrC->ptrm; aux = aux + 1){
        printf("\n %d", *aux);
    }
    

    return 0;
}


int menu (){
    int eleccion;
    printf("\n\nIngrese una opcion valida: ");
    printf("\n1.- Meter numero ");
    printf("\n2.- Sacar numero ");
    printf("\n3.- Imprimir ");
    printf("\n4.- Salir \n");
    scanf("%d",&eleccion);
    return eleccion;
}


int main(){
  struct Cola cola, *miptrC;
  int miDato;
  miptrC = &cola;

  miptrC->ptrm = miptrC->arreglo;
  miptrC->ptrs = miptrC->arreglo;


      for(;;){

        switch (menu())
        {
        case 1:
            if(estaColaLlena(miptrC))
                printf("La cola esta llena");
            else{
                printf("\n\nMETER DATOS");
                scanf("%d", &miDato);
                meterCola(miptrC, miDato);
            }
            break;

        case 2:
            if(estaColaVacia(miptrC))
                printf("\n\nLa cola esta vacia ");
            else{
                printf("\n\nSACAR DATOS");
                printf("\n\nEl dato sacado es: %d",sacarCola(miptrC));
            }
            break;

        case 3:
            imprimirCola(miptrC);

            break;
            
        case 4:
            exit(0);
            break;

        default:
            printf("\n\nElija una opción valida.");
        }
    }

}