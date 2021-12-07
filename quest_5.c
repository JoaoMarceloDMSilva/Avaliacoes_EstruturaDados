#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Escreva um programa que cadastre uma lista de números. Deve-se ter uma função para remover 
da lista os números negativos.
*/

struct listaNumeros{
  float numeros;
  struct listaNumeros *prox;
};

typedef struct listaNumeros Lista;
Lista *inicio;
int tamanho = 0;

void inserirInicio () {
  Lista *lista = (Lista*) malloc(sizeof(Lista));
  printf("Inserir um valor:\n");
  scanf("%f", &lista->numeros);

  lista -> prox = inicio;
  inicio = lista;
  tamanho++;
}

void inserirFinal(){
  Lista *lista = (Lista*) malloc(sizeof(Lista));
  printf("Inserir um valor:\n");
  scanf("%f", &lista->numeros);

  lista -> prox = NULL;
  if (inicio == NULL){
    inicio = lista;
  }else{
    Lista *aux = inicio;
    while(aux->prox != NULL){
      aux = aux -> prox;
    }
    aux -> prox = lista;
  }
  tamanho++;
}

void inserirIndex(int index){
  if(index > tamanho){
    printf("ERRO: posição inválida!\n");
    exit (1);

  }else if(index == 0){
    inserirInicio();

  }else{
    Lista *aux = inicio;
    int i = 0;
    while (i != index-1){
      aux = aux -> prox;
      i++;
    }
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    printf("Inserir um valor:\n");
    scanf("%f", &lista->numeros);

    lista -> prox = aux -> prox;
    aux -> prox = lista;
    tamanho++;
  }
}

//Revomer
void removerNegativo (Lista *lista) {
  if (lista != NULL){
    if (lista -> numeros < 0){
      Lista *excluir = lista -> prox;
      lista -> prox = lista -> prox -> prox;
      free(excluir);
      tamanho--;
    }
    removerNegativo(lista -> prox);
  }
}

void imprimirLista (Lista *lista) {
  if (lista != NULL){
    printf("%.1f -> ", lista->numeros);
    imprimirLista(lista -> prox);
  }else{
    printf("NULL\n");
  }
}

int main(void){
  int op, index;

  do{
    printf("\n1 - Inserir no início\n2 - Inserir no fim\n3 - Inserir em um lugar arbitrário\n4 - Imprimir\n");
    printf("5 - Excluir\n0 - Sair\n");
    scanf("%d", &op);

    switch (op){
      case 1:
        inserirInicio();
      break;

      case 2:
        inserirFinal();
      break;

      case 3:
        printf("\nInforme a posição: ");
        scanf("%d", &index);
        inserirIndex(index);
      break;

      case 4:
        printf("\n");
        imprimirLista(inicio);
        printf("\n");
      break;

      case 5:
        removerNegativo(inicio);
      break;

      case 0:
        printf("\nSaindo...\n");
      break;

      default:
      printf("\nERRO: opção inválida!\n");
    }
  }while(op != 0);
  return 0;
}
