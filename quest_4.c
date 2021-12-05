#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Escreva uma função que receba, como parâmetros, duas lista L1 e L2 e concatene L1 no final de 
L2. Utilize o protótipo: Lista *concatena(Lista *L1, Lista *L2).
*/

struct lista {
  int num;
  struct lista *prox;
};

typedef struct lista Lista;
Lista *p1;
Lista *p2;


void inserirNaLista1 (int x) {
  Lista *l = malloc(sizeof(Lista));
  l->num = x;

  l -> prox = p1;
  p1 = l;
}

void inserirNaLista2 (int y) {
  Lista *l = malloc(sizeof(Lista));
  l->num = y;

  l -> prox = p2;
  p2 = l;
}

void imprimirLista (Lista *l) {
  if (l != NULL){
    printf("%d -> ", l->num);
    imprimirLista(l -> prox);
  }else{
    printf("NULL\n");
  }
}

void inverte(Lista *l1, Lista *l2){
  Lista *aux;
  aux = l1->prox;
  while(aux -> prox != NULL){
    aux = aux->prox;
  }
  aux->prox = l2->prox;
  free(l2);
}

int main(void){
  int l;
  inserirNaLista1(4);
  inserirNaLista1(3);
  inserirNaLista1(2);
  inserirNaLista1(1);

  printf("\nLista 1:\n");
  imprimirLista(p1);

  inserirNaLista2(8);
  inserirNaLista2(7);
  inserirNaLista2(6);
  inserirNaLista2(5);

  printf("Lista 2:\n");
  imprimirLista(p2);

  inverte(p1,p2);
  printf("\nLista concatenada:\n");
  imprimirLista(p1);
  return 0;
}
