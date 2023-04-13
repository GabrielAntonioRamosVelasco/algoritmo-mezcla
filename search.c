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

/*Implementación del método de ordenamiento mezcla
  Permite ordenar cualquier tipo de datos. Para ello utiliza un 
  apuntador a la función que sabe comparar los datos que están en
  el arreglo ar.
    
  En este caso hay se utilizan dos funciones, "mezclaSort" para ir dividiendo en
  dos el arreglo de forma recursiva y la otra "mezcla" para mezclar (ordenar) los
  elementos de estos arreglos divididos.
  La primer función necesita como parámetros extra el "inicio" y "fin" del arreglo a
  ordenar, de ahí salen dos subarreglos que seguirán dividiendose.
  Posteriormente para la mezcla también se necesita el "inicio","fin" y también la mitad
  que será obtenida en mezclaSort, esto para ordenar la primer mitad del arreglo
  original y después la otra.
  
  
  
  */

void mezclaSort(void* ar, int tam_ar , int tam_dat, ap_fun fcmp, int* cont,int inicio, int fin){ 
  
  if(inicio < fin){ 
    int mitad= inicio + (fin-inicio) /2;
    mezclaSort(ar,tam_ar,tam_dat,fcmp,cont,inicio,mitad);
    mezclaSort(ar,tam_ar,tam_dat,fcmp,cont,mitad+1,fin);
    mezcla(ar,tam_ar,tam_dat,fcmp,cont,inicio,mitad,fin);
  }
}

/*El algoritmo consiste en ir comparando dos posiciones, donde
se irán haciendo swaps de tal forma que queden ordenadas de
menor a mayor, todo esto con ayuda de un arreglo de datos 
auxiliar

*/

void mezcla(void* ar, int tam_ar , int tam_dat, ap_fun fcmp, int* cont, int inicio, int mitad, int fin){ 
  int i,j,k;
 


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