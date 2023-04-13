/***************************************************************
*Implementación simple de de un método que ordena cualquier    *
* tipo de datos                                                *
***************************************************************/

#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <string.h>   /* Para utilizar memcpy*/

/*Define apuntador a función que compara dos tipos de datos
  de los que va a ordenar */
typedef int (*ap_fun)(const void*, const void*,int*);

/*Implementacion del algoritmo de la burbuja
Recibe
  arr Apuntador sin tipo, que tiene la dirección del arreglo
      a ser ordenado
  tam Entero que representa el numero de datos que tienen el
      arreglo
  tam_dat  El numero de bytes que ocupa cada dato que esta 
      en el arreglo
  fcmp Apuntador a la función que compara dos datos que estan
      en el arreglo
  cont Entero pasado por referencia para saber cuantas veces se
       invoco a la funcion comparar y a la funcion intercambio
       (swap)
      */
int* slice(void* ar, int tam_ar , int tam_dat, ap_fun fcmp, int* cont,int inicio, int fin);
void mezclaSort(void* ar, int tam_ar , int tam_dat, ap_fun fcmp, int* cont,int inicio, int fin);
void mezcla(void* ar, int tam_ar , int tam_dat, ap_fun fcmp, int* cont, int inicio, int mitad, int fin);


#endif