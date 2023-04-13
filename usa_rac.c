#include <stdio.h>
#include <stdlib.h>
#include "racional.h"
#include "search.h"

#define TOT_PRO    3     /*Veces que se repite el experimento
                            para calcular el promedio*/
#define MAX_N      100  /*Limite de elementos a ordenar*/
#define MIN_N      10    /*Tamaño inicial del arreglo a ordenar*/
#define PAS_N      10    /*Incremento con que cambia el tamaño
                            del arreglo a ordenar*/

/* Función que compara dos elementos cualesquiera que están
   en el arreglo*/
int comp_rac_v(const void* a, const void* b,int* cuenta){
  (*cuenta)++;
  return cmp_rac((const racional*)a,(const racional*)b);
}

int main(){
  racional a[MAX_N];
  
  char sal[TAM_CAD_TEM];
  int i,j,k,l;
  int cuenta;        /*Operaciones cada vez que se ordena*/
  float acumulador;  /*Suma acumulada para calcular promedio*/

  /*Hace variar el número de elementos en el arreglo 
    a ordenar*/
  for(i=MIN_N;i<MAX_N;i+=PAS_N){
    acumulador = 0;

    /*Repite el experimento TOT_PRO para el mismo número de 
      elementos en el arreglo y así calcular el promedio*/
    for(k=0;k<TOT_PRO;k++){
      /*Asigna i elementos al azar al arreglo a*/
      for(j=0;j<i;j++)
        set_ale_rac(a+j);

      cuenta = 0;
      
      mezclaSort(a,i,sizeof(racional),comp_rac_v,&cuenta,-1,i);
       printf("Hola\n");

      for(l=0;l<i;l++)
        printf("%s\n",tostr_rac(sal,a+l));
      acumulador+=cuenta;
    }
    printf("%d\t%f\n",i,acumulador/TOT_PRO);
    
  }

  return 0;
}