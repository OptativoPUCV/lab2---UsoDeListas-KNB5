#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() 
{
  List* L = create_list();
  int i;
  int *elemento;
  for (i = 1; i <= 10; i++){
    elemento = (int *)malloc(sizeof(int));
    *elemento = i;
    pushBack(L, elemento);
  }
  return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) 
{
  int suma = 0;
  int *elemento;
  elemento = (int*)first(L);
  while(elemento != NULL)
    {
      suma += *(int *)elemento;
      elemento = next(L);
    }
  return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem)
{
  int* elemento = (int *)first(L);

  while(elemento != NULL)
    {
      if(*(int*)elemento == elem)
      {
        popCurrent(L);
      }
      elemento = next(L);
    }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) 
{
  int* elemento = (int *)first(P1);
  int cont = 1;

  while(elemento != NULL)
    {
      if(cont == 1)
      {
        pushFront(P2, elemento);
        cont++;
      }
      else
      {
        pushBack(P2, elemento);
      }
      elemento = next(P1);
    }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) 
{

  Stack* stack = create_stack();

  /*int largo = strlen(cadena);
  
  if(largo % 2 == 0)
    { 
      for(int j = 0; j < largo; j++)
        {
          pushBack(stack, &cadena[j]);
        }

      char *elemento = (char *) top(stack);

      for(int k = 0; k < largo; k++)
        {
          switch(*elemento)
            {
              case ')':
                if(*(char*)pop(stack) != '(')
                {
                  return 0;
                }
                break;
              case '}':
                if(*(char*)pop(stack) != '{')
                {
                  return 0;
                }
                break;
              case ']':
                if(*(char*)pop(stack) != '[')
                {
                  return 0;
                }
                break;
            }
        }
    }*/
  
  int i, j;

  int largo = strlen(cadena);

  if (largo % 2 == 1) return 0;

  for (i = 0, j = largo - 1; i < j; i++, j--)
  {
    switch (cadena[i])
    {
      case '(':
        if (cadena[j] != ')') return 0;
        break;
      case '{':
        if (cadena[j] != '}') return 0;
        break;
      case '[':
        if (cadena[j] != ']') return 0;
        break;
      
    }
  }
  return 1;
}
