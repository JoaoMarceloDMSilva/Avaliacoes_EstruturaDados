#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
a) quantidade_livros – a função recebe por parâmetro o endereço do primeiro elemento da lista 
encadeada e deve retornar a quantidade total de livros em estoque (somatório dos campos 
quantidade existentes na estrutura dos nós da lista);

b) livros_ano – a função recebe por parâmetro o endereço do primeiro elemento da lista encadeada 
e um determinado ano. A função deve exibir na tela os dados de todos os livros existentes na lista 
que foram publicados no ano especificado. Obrigatoriamente a função deve ser implementada de 
forma recursiva;
*/

struct noDaLista {
 char titulo[51]; 
 char autor[51]; 
 int ano; 
 int quantidade; 
 struct noDaLista *prox; 
};

typedef struct noDaLista Lista;
Lista *primeiro;

void cadastrarLista () {
  printf("\n");
  getchar();
  Lista *lista = malloc(sizeof(Lista));
  printf("Título:\n");
  fgets(lista->titulo, 51, stdin);
  printf("Autor:\n");
  fgets(lista->autor, 51, stdin);
  printf("Ano: ");
  scanf("%d", &lista->ano);
  printf("Quantidade: ");
  scanf("%d", &lista->quantidade);

  lista -> prox = primeiro;
  primeiro = lista;
}

void imprimirLista (Lista *lista) {
  if (lista != NULL){
    printf("Título: %s", lista->titulo);
    printf("Autor: %s", lista->autor);
    printf("Ano: %d\tQuantidade: %d\n", lista->ano, lista->quantidade);
    printf("- - - - - - - - - - - -\n");

    imprimirLista(lista->prox);
  }
}

int quantidadeLivros (Lista *lista){
  int aux=0;
  while (lista != NULL) {
    aux = aux + (lista -> quantidade);
    lista = lista->prox;
  }
  
  return aux;
}

void pesquisaListaAno (Lista *lista, int ano) {
  if (lista != NULL){
    if (ano == lista->ano) {
      printf("Título: %s", lista->titulo);
      printf("Autor: %s", lista->autor);
      printf("Ano: %d\tQuantidade: %d\n", lista->ano, lista->quantidade);
      printf("- - - - - - - - - - - -\n");
    }
    pesquisaListaAno (lista -> prox, ano);
  }
}


int main(void) {
  int op, qtd_livros, ano;
  do{
    printf("\n-_-_-_-_-_-_-_ MENU -_-_-_-_-_-_-_\n");
    printf("1 -> Cadastrar livro\n2 -> Imprimir cadastro\n");
    printf("3 -> Quantidade total de livros\n4 -> Pesquisar por Ano\n0 -> Sair\n");
    printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    scanf("%d", &op);

    switch(op){
      case 1:
        cadastrarLista();
      break;

      case 2:
        imprimirLista(primeiro);
      break;

      case 3:
        qtd_livros = quantidadeLivros(primeiro);
        printf("\nQuantidade de livros cadastrados: %d\n", qtd_livros);
      break;

      case 4:
        printf("Informe o ano: ");
        scanf("%d", &ano);
        printf("\n");
        pesquisaListaAno(primeiro,ano);
      break;

      case 0:
        printf("Saindo...\n");
      break;

      default:
        printf("ERRO: opção inválida!\n");
    }
  }while(op!=0);
  return 0;
}
