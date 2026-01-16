import numpy as np
import pandas as pd
arreglo = np.array([1,2,5,7])
lista = [6,2,5,7]
print(f"la posicion tres de arreglo es:{arreglo[2]}")
print(f"la posicion cero de la lista es:{lista[0]}")
### dimencion de vectores

dim = len(arreglo)
dim_lista = len(lista)

print("la posicion tres de arreglo es:", dim )
print("la posicion cero de la lista es:", dim_lista)


###  el shape esta recomendado para matrices, nos dara fila , columnas 
dim2 = np.shape(arreglo)
dim2_lista = np.shape(lista)
print("la posicion tres de arreglo es:", dim2 )
print("la posicion cero de la lista es:", dim2_lista)



###################
#####cliclo for sirve para recorrer todo el arregolos,lista o data frame (vector o matriz)
## suponga que si hay valores mayoresa a 5 , se tomaran como valores atipicos y estos
## se deben poner en 0 for tambien es de tipo local
for i in range(dim):
 if arreglo[i]>5:
  arreglo[i]= 0
 print(arreglo)

##recorer la matriz

matriz = np.array([[0,6,0,1],[-4,2,6,1],[8,6,9,-10],[10,6,3,12]])
print(np.shape(matriz)[0])
filas , columnas = np.shape(matriz)
for i in range (filas):
     for j in range (columnas):
       
       if (matriz [i][j] <= 0 or matriz [i][j]>6):
         matriz [i][j] = 1
       ##print(matriz[i][j])


### data frames 
## pandas es una librerira para la lectura de datos por ejemplo tablas de excel
### en sus diefrentes formatos y permite hacer un analisis rapidode los datos
## y mostarralos y manejarlos de forma mas eficiente

