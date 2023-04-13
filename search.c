#include "search.h"
#include <stdio.h>
#include <stdlib.h>

/*Funcion que intercambia
  El valor que esta en la dirección x pasara a estar en la 
  direccion y y el que esta en la direccion y pasará a  la 
  dirección x.
  Utiliza un arreglo temporal de tamaño variable.
  También cuenta el número de veces que se ha invocado a la
  funcion*/
void swap(void* x, void* y, int tam_dat,int* cuenta){
  unsigned char aux[tam_dat];
  (*cuenta)++;
  memcpy(aux,x,tam_dat);
  memcpy(  x,y,tam_dat);
  memcpy(y,aux,tam_dat);
  return;
}

/*Implementación del método de ordenamiento shell
  Permite ordenar cualquier tipo de datos. Para ello utiliza un 
  apuntador a la función que sabe compoarar los datos que están en
  el arreglo ar.
  El último parámetro es un contador que permite saber cuantas veces
  se invocó a la función swap y a la función que compara los datos 
  para aproximar la complejidad
  
  En este caso la variable "i" sirve para ir recorriendo todas las posciciones
  y las variables "j" y "k" sirven para acceder a los contenidos del arreglo,
  De tal manera que se empiezan a hacer saltos desde la mitad y se comparan
  si el dato de la izquierda es menor al de la derecha, en ese caso se hace un swap
  y así sucesivamente partiendo a la mitad cada vez hasta llegar a lo mínimo.
  
  
  */

void mezclaSort(void* ar, int tam_ar , int tam_dat, ap_fun fcmp, int* cont,int inicio, int fin){ 
  
  if(inicio < fin){ 
    int mitad= inicio + (fin-inicio) /2;
    mezclaSort(ar,tam_ar,tam_dat,fcmp,cont,inicio,mitad);
    mezclaSort(ar,tam_ar,tam_dat,fcmp,cont,mitad+1,fin);
    mezcla(ar,tam_ar,tam_dat,fcmp,cont,inicio,mitad,fin);
 
  }
}

void mezcla(void* ar, int tam_ar , int tam_dat, ap_fun fcmp, int* cont, int inicio, int mitad, int fin){ 
  int i,j,k;
  int tam1,tam2;
  tam1=mitad-inicio+1;
  tam2= fin-mitad;


  void *aux=(void*) malloc((fin-inicio+1) * tam_dat*tam_ar);
  
  i=inicio;
  j= mitad+1;
  k=0;

  while (i<=mitad && j<=fin)
  {
    if(fcmp(ar+i*tam_dat,ar+j*tam_dat,cont)==-1){
        swap(aux+k*tam_dat,ar+i*tam_dat,tam_dat,cont);
        i++;
        }else{
          swap(aux+k*tam_dat,ar+j*tam_dat,tam_dat,cont);
          j++;
        }
        k++;
  }

  while (i<=mitad){
    swap(aux+k*tam_dat,ar+i*tam_dat,tam_dat,cont);
    i++;
    k++;
  }

  while (j<=fin){
    swap(aux+k*tam_dat,ar+j*tam_dat,tam_dat,cont);
    j++;
    k++;
  }

  for (i = inicio; i <= fin; i++)
  {
    swap(ar+i*tam_dat,aux+(i-inicio)*tam_dat,tam_dat,cont);
  }
  
  free(aux);
}