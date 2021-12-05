#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Considere a implementação de listas encadeadas utilizando ponteiros. Escreva uma função void 
Inverte(TipoLista *Lista) que, dada uma lista com um número qualquer de elementos, inverte a 
ordem dos elementos da lista.
*/

struct lista {
  int num;
  struct lista *prox;
};

typedef struct lista Lista;
Lista *primeiro;

void inserirNaLista (int x) {
  Lista *l = malloc(sizeof(Lista));
  l->num = x;

  l -> prox = primeiro;
  primeiro = l;
}

void imprimirLista (Lista *l) {
  if (l != NULL){
    printf("%d -> ", l->num);
    imprimirLista(l -> prox);
  }else{
    printf("NULL\n");
  }
}

Lista *inverte(Lista *lista)
{
  Lista *anterior,*atual, *segundo;
  anterior =NULL;
  atual = lista;
  while(atual != NULL){
    segundo = atual -> prox;
    atual -> prox = anterior;
    anterior = atual;
    atual = segundo;
  }

  return anterior;
}


int main(void){
  inserirNaLista(8);
  inserirNaLista(7);
  inserirNaLista(6);
  inserirNaLista(5);
  inserirNaLista(4);
  inserirNaLista(3);
  inserirNaLista(2);
  inserirNaLista(1);

  imprimirLista(primeiro);
  primeiro = inverte(primeiro);

  imprimirLista(primeiro);

  return 0;
}
