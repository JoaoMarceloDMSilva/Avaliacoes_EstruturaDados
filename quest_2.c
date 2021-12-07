#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
A. Declare os tipos necessários para a implementação dessa estrutura. 

B. Escreva um procedimento para cadastrar dois amigos:
void Relaciona(int Amigo1, int Amigo2, TipoFace* pFace)

Considere que o Amigo1 já está cadastrado no Facebook, enquanto o Amigo2 pode ou não já estar 
cadastrado.

*/

struct listaFacebook {
  char nome[40];
  int id;
  struct listaFacebook *prox;
  struct listaFacebook *amigo;
};

typedef struct listaFacebook Face;
Face *inicio;
int identificador = 0;

void cadastro () {
  getchar();
  Face *lista= (Face*) malloc(sizeof(Face));
  printf("Informe o nome da pessoa:\n");
  fgets(lista->nome, 40, stdin);
  
  lista -> prox = NULL;
  if (inicio == NULL){
    inicio = lista;
  }else{
    Face *aux = inicio;
    while(aux -> prox != NULL){
      aux = aux -> prox;
    }
    aux -> prox = lista;
  }

  identificador++;
  lista -> id = identificador;
}

//Adicionar amigo
void adicionarAmigo(int amigo1, int amigo2, Face *lista){
  Face *aux = inicio;
  aux = lista;

  if (lista == NULL){
    printf("Amigo inexistente.\n");
    exit (1);
  }
  else{
    while(amigo1 != aux -> id) {
      aux = aux -> prox;
    }
    if (amigo1 == aux -> id) {
      Face *aux2 = inicio;
      
      while((amigo2 != aux2 -> id) && (aux2 -> prox != NULL)){
        aux2 = aux2 -> prox;
      }

      if(amigo2 == aux2 -> id) {
        Face *aux3 = aux;
        while(aux3 -> amigo != NULL){
          aux3 = aux3 -> prox;
        }
        aux3 -> amigo = aux2;
      }
    }
  }
  printf("Parabéns!\n%se %s são novos amigos.", aux -> nome, aux -> amigo -> nome);
  
}

void imprimir (Face *L) {
  if (L != NULL) {
    printf("Nome: %s", L -> nome);
    printf("ID: %d\n", L -> id);
    
    imprimir(L -> prox);
  }
}


int main(void){
  int op, id1, id2;
  do {
    printf("\n\n1 - Cadastrar\n2 - Adicionar à lista de amigos\n3 - Imprimir Lista\n0 - Sair\n");
    printf("Opção: ");
    scanf("%d", &op);
    switch (op) {
      case 1:
        cadastro();
      break;

      case 2:
        printf("Informe o ID da primeira pessoa: ");
        scanf("%d", &id1);
        printf("Informe o ID da segunda pessoa: ");
        scanf("%d", &id2);

        adicionarAmigo(id1, id2, inicio);
      break;

      case 3:
        imprimir(inicio);
      break;

      case 0:
        printf("\nSaindo...\n");
      break;

      default:
        printf("\nERRO: opção inválida\n");
    }
  }while(op != 0);

  return 0;
}
