#include "racional.h"
/*                       Locales                              */
/* Reduce la fracción a su expresión con el número entero más
   y una fracción propia.
*/
static int reducir(racional* r){ 
  if (!AP_VAL(r))
    return AP_INV;
  /*Convierte la parte entera a fracción*/
  int num = r->num;
  num+=r->ent*r->den;
  /*el signo del númerador el denominador */
  r->sig = num*r->den<0?-1:1;
  /*Reduce la fracción utilizando sólo números positivos*/
  r->ent=abs(num)/abs(r->den);
  r->num=abs(num)%abs(r->den);
  r->den=abs(r->den);
  return OK;
}

/*                    CONSTRUCTURAS                           */
/* Inicializa un racional.
Recibe: Apuntador a racional que será inicializado a cero
Regresa: Código de error en caso de recibir apuntador invalido
*/
int ini_rac(racional* r){
  if (!AP_VAL(r))
    return AP_INV;
  
  r->num = 0;
  r->den = 1;
  r->ent = 0;
  r->sig = 1;
  return OK;
}

/* Modifica el numerador del racional
Recibe: Apuntador a racional que será modificado
        Número entero que se convertirá en el numerador,
           puede ser positivo o negativo
Regresa: Código de error en caso de recibir apuntador invalido
Observación: reduce la fracción después de realizar la 
         modificación
*/
int set_num_rac(racional* r, int num){
  if (!AP_VAL(r)&&VAL_RAC(*r))
    return AP_INV;
  r->num=num;
  reducir(r);
  return OK;
}

/* Modifica el denominador del racional
Recibe: Apuntador a racional que será modificado
        Número entero que se convertirá en el denominador,
           puede ser positivo o negativo, pero no cero
Regresa: Código de error en caso de recibir apuntador invalido
         Código de error en caso de recibir den==0
Observación: reduce la fracción después de realizar la 
         modificación
*/
int set_den_rac(racional* r, int den){
  if (!AP_VAL(r)&&VAL_RAC(*r))
    return AP_INV;
  if(!(den!=0))
    return DEN_CERO;
  r->den = den;
  reducir(r);
  return OK;
}

/* Modifica la parte entera del racional
Recibe: Apuntador a racional que será modificado
        Número entero que se convertirá en la parte entera,
           puede ser positivo o negativo
Regresa: Código de error en caso de recibir apuntador invalido
Observación: reduce la fracción después de realizar la 
         modificación
*/
int set_ent_rac(racional* r, int ent){
  if (!AP_VAL(r)&&VAL_RAC(*r))
    return AP_INV;
  r->ent = ent;
  reducir(r);
  return OK;
}

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
int set_ale_rac(racional* r){
  if (!AP_VAL(r)&&VAL_RAC(*r))
    return AP_INV;
  r->num = rand()%MAX_RAN;
  /*Se suma uno para evitar denominaror 0*/
  r->den = rand()%MAX_RAN+1;
  r->ent = rand()%MAX_RAN;
  r->sig = rand()%2?1:-1;
  reducir(r);
  return OK;
}
/*                    OBSERVADORAS                            */
/* Obtiene el númerador de un racional
Recibe:  Entero por referencia para almacenar el númerador
         Apuntador a racional del que se extraé el númerador
Regresa: Código de error en caso de recibir apuntador invalido
*/
int get_num_rac(int* n, const racional* r){
  if (!(AP_VAL(r)&&AP_VAL(n)&&VAL_RAC(*r)))
    return AP_INV;
  *n = r->num;
  return OK;
}

/* Obtiene el denominador de un racional
Recibe:  Entero por referencia para almacenar el denominador
         Apuntador a racional del que se extraé el denominador
Regresa: Código de error en caso de recibir apuntador invalido
*/
int get_den_rac(int* n, const racional* r){
  if (!(AP_VAL(r)&&AP_VAL(n)&&VAL_RAC(*r)))
    return AP_INV;
  *n = r->den;
  return OK;
}

/* Obtiene la parte entera de un racional
Recibe:  Entero por referencia para almacenar la parte entera|
         Apuntador a racional del que se extraé la parte entera
Regresa: Código de error en caso de recibir apuntador invalido
*/
int get_ent_rac(int* n, const racional* r){
  if (!(AP_VAL(r)&&AP_VAL(n)&&VAL_RAC(*r)))
    return AP_INV;
  *n = r->ent;
  return OK;
}

/* Compara dos numeros racionales 
Recibe:  Apuntadores a racionales a comparar
Regresa: Código de error en caso de recibir apuntador invalido
         1 si r>s
         0 si r == s
        -1 si r<s
*/
int cmp_rac(const racional* r,const racional* s){
  double rac1,rac2;
  if (!(AP_VAL(r)&&AP_VAL(s)))
    return AP_INV;
  if (!(VAL_RAC(*r)&&VAL_RAC(*s)))
    return AP_INV;
  rac1 = r->sig*(r->ent+(double)r->num/r->den);
  rac2 = s->sig*(s->ent+(double)s->num/s->den);
  return rac1>rac2?1:rac1<rac2?-1:0;
}

/* Convierte el racional a una representación de cadena
Recibe: Cadena que debe tener espacio suficiente para almacenar
       la representación del racional.
Regresa: La cadena "error" en caso de recibir apuntadores no
       validos
Observaciones:
- Utiliza una cadena temporal para representar cada entero, el 
  tamño de esta cadena es TAM_CAD_TEM
*/
char* tostr_rac(char* sal, const racional* r){
  char tmp[TAM_CAD_TEM];  
  
  if (!(AP_VAL(sal)&&AP_VAL(r)&&VAL_RAC(*r)))
    return "error";
  
  strcpy(sal,"");
  if(ES_ENTERO(*r))
    sprintf(tmp,"%d",r->sig*r->ent);
  else
    if(ES_PROPIA(*r))
      sprintf(tmp,"(%d/%d)",r->sig*r->num,r->den);
    else
      sprintf(tmp,"(%d %d/%d)",r->sig*r->ent,r->num,r->den);
  
  strcat(sal,tmp);
  return sal;
}