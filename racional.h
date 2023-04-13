/***************************************************************
*Implementación simple de los números racionales, tanto        *
fracciones propias como impropias                              *
***************************************************************/

#ifndef _RACIONAL_H
#define _RACIONAL_H

#include <string.h>
#include <stdio.h>
#include "error.h"       /* Define constantes de error comunes*/
/***************************************************************
*                    C O N S T A N T E S                       *
***************************************************************/
#define  DEN_CERO        201   /*Denominador con valor cero*/
#define  MAX_RAN         100   /*Número máximo para generar 
                                 números racionales aletaorios*/
#define  TAM_CAD_TEM      20   /*Tamaño de cadena temporal para
                                 representar los enteros al 
                                 convertir a cadena*/
/***************************************************************
*                        M A C R O S                           *
***************************************************************/
                         /* Es cero si el numerador y la parte
                            entera son cero*/
#define  ES_CERO(x)      ((x).ent==0 && (x).num==0)
                         /* Es fracción propia si la parte 
                            entera no es cero, como 1/2 */
#define  ES_PROPIA(x)    ((x).ent==0 && (x).num!=0)
                         /* Es impropia si tanto el númerador
                            como la parte entera no son cero,
                            como en (3 1/2)*/
#define  ES_IMPROPIA(x)  ((x).ent!=0 && (x).num!=0)
                         /* Es número entero si el numerador 
                            es cero, como 4*/
#define  ES_ENTERO(x)    ((x).num==0)
                         /* Para ser un racional valido se
                            requiere que el denominador sea
                            diferente de cero*/
#define  VAL_RAC(r)      ((r).den!=0)
/***************************************************************
*          D E F I N I C I O N     D E     T I P O S           *
***************************************************************/
/*El tipo racional se define con cuatro números enteros*/
typedef struct{
  int num;             /* Númerador de la parte fraccionaria*/
  int den;             /* Denominador de la parte fraccionaria*/
  int ent;             /* Parte entera del número*/
  int sig;             /* signo del número*/
} racional;
/***************************************************************
*                     F U N C I O N E S                        *
***************************************************************/
/*                    CONSTRUCTURAS                           */
/* Inicializa un racional.
Recibe: Apuntador a racional que será inicializado a cero
Regresa: Código de error en caso de recibir apuntador invalido
*/
int ini_rac(racional* r);

/* Modifica el numerador del racional
Recibe: Apuntador a racional que será modificado
        Número entero que se convertirá en el numerador,
           puede ser positivo o negativo
Regresa: Código de error en caso de recibir apuntador invalido
Observación: reduce la fracción después de realizar la 
         modificación
*/
int set_num_rac(racional* r, int num);

/* Modifica el denominador del racional
Recibe: Apuntador a racional que será modificado
        Número entero que se convertirá en el denominador,
           puede ser positivo o negativo, pero no cero
Regresa: Código de error en caso de recibir apuntador invalido
         Código de error en caso de recibir den==0
Observación: reduce la fracción después de realizar la 
         modificación
*/
int set_den_rac(racional* r, int den);

/* Modifica la parte entera del racional
Recibe: Apuntador a racional que será modificado
        Número entero que se convertirá en la parte entera,
           puede ser positivo o negativo
Regresa: Código de error en caso de recibir apuntador invalido
Observación: reduce la fracción después de realizar la 
         modificación
*/
int set_ent_rac(racional* r, int den);

/* Generá un número racional de forma aleatoria
Recibe: Apuntador a racional que será modificado
Regresa: Código de error en caso de recibir apuntador invalido
Observación: Asigna números aleatorios a la parte entera, el 
         numerador, denominador (no puede ser cero) y también
         al signo utilizando módulo 2.
         Utiliza la constante MAX_RAN para asignar enteros 
         entre 0 y MAX_RAN-1
         reduce la fracción después de realizar la modificación
*/
int set_ale_rac(racional* r);

/*                    OBSERVADORAS                            */
/* Obtiene el númerador de un racional
Recibe:  Entero por referencia para almacenar el númerador
         Apuntador a racional del que se extraé el númerador
Regresa: Código de error en caso de recibir apuntador invalido
*/
int get_num_rac(int* n, const racional* r);

/* Obtiene el denominador de un racional
Recibe:  Entero por referencia para almacenar el denominador
         Apuntador a racional del que se extraé el denominador
Regresa: Código de error en caso de recibir apuntador invalido
*/
int get_den_rac(int* n, const racional* r);

/* Obtiene la parte entera de un racional
Recibe:  Entero por referencia para almacenar la parte entera|
         Apuntador a racional del que se extraé la parte entera
Regresa: Código de error en caso de recibir apuntador invalido
*/
int get_ent_rac(int* n, const racional* r);

/* Compara dos numeros racionales 
Recibe:  Apuntadores a racionales a comparar
Regresa: Código de error en caso de recibir apuntador invalido
         1 si r>s
         0 si r == s
        -1 si r<s
*/
int cmp_rac(const racional* r,const racional* s);

/* Convierte el racional a una representación de cadena
Recibe: Cadena que debe tener espacio suficiente para almacenar
       la representación del racional.
Regresa: La cadena "error" en caso de recibir apuntadores no
       validos
Observaciones:
- Utiliza una cadena temporal para representar cada entero, el 
  tamño de esta cadena es TAM_CAD_TEM
*/
char* tostr_rac(char* sal, const racional* r);

#endif