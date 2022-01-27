#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct player {
  int shirt_num;
  char name[50];
  struct player *left;
  struct player *right;
};

typedef struct player Player;

Player* create(int soccer_player){
  Player *position = malloc(sizeof(Player));
  position->shirt_num = soccer_player;
  position->left = NULL;
  position->right = NULL;

  return position;
}

void add (Player *n, int num) {
  if (num == n->shirt_num){
    return;
  }

  if (num < n->shirt_num){

    if (n->left == NULL){
      n->left = create(num);
    }
    else {
      add(n->left, num);
    }

  }else{

    if (n->right == NULL){
      n->right = create(num);
    }
    else{
      add(n->right, num);
    }
  }
}

void remove_player(Player *root, int num){
  Player *child = root;
  Player *father;

  do{
    father = child;
    if (num < child->shirt_num){
      child = child->left;
    }
    else if(num > child->shirt_num){
      child = child->right;
    }
  }while(child != NULL && child->shirt_num != num);

  if(child != NULL){

    if(child->left == NULL && child->right == NULL) {

      if(father->left == child){
        father->left = NULL;
      }
      else if(father->right == child){
        father->right = NULL;
      }
    }

    if(child->left != NULL && child->right == NULL){

      if(father->left == child){
        father->left = child->left;
      }
      else if(father->right == child){
        father->right = child->left;
      }
      
    }
    
    if(child->left == NULL && child->right != NULL){

      if(father->left == child){
        father->left = child->right;
      }
      else if(father->right == child){
        father->right = child->right;
      }
      
    }

    if(child->left != NULL && child->right != NULL){
      if(child->left->right == NULL){
        child->shirt_num = child->left->shirt_num;
        child->left = NULL;
      }
      else{
        Player *n =child->left;
        Player *aux = n;
        while(n->right != NULL){
          aux =n;
          n = n->right;
        }
        aux->right = NULL;
        child->shirt_num = n->shirt_num;
      }
    }
    printf("\nAdicione o novo jogador:\nNúmero da camisa: ");
    scanf("%d", &num);
    add(root, num);
  }
}

void to_print (Player *n) {
  if (n == NULL) {
    return;
  }
  printf("\n%d", n->shirt_num);
  to_print(n->left);
  to_print(n->right);
}

int counting_nodes (Player *root){
  if(root == NULL){
    return 0;
  }
  else{
    return 1 + counting_nodes(root->right) + counting_nodes(root->left);
  }
}

int main () {
  int op, start, info;
  int height, quant_nodes;

  printf("PASSO INICIAL:\nInsira um número do goleiro: ");
  scanf("%d", &start);
  Player *root = create(start);

  do{
    printf("\n\n1 - Adicionar valor\n2 - Imprimir árvore\n3 - Remover um valor\n4 - Achar o maior valor\n5 - Altura da árvore\n6 - Quantidade de nós\n0 - Sair\nOpção: ");
    scanf("%d", &op);
    switch(op){
      case 1:
        quant_nodes = counting_nodes(root);
        if (quant_nodes < 11){
          printf("\nInsira um valor inteiro para adicionar: ");
          scanf("%d", &info);
          add(root, info);
        } else {
          printf("\nSeu time está cheio!");
        }
      break;

      case 2:
        to_print(root);
      break;

      case 3:
        printf("\nInserir um valor para remover: ");
        scanf("%d", &info);
        remove_player(root, info);
      break;

      case 0:
        printf("\nSaindo ...");
      break;

      default:
        printf("\nERRO: Opção inválida!\n");

    }
  }while(op != 0);
  return 0;
}
