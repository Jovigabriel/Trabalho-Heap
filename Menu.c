#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Variável Global
int tam = 0;


void menu() {
  int op;
  int teste = 0;
  char continua[5] = "sim";
  int res;
  int total = 0;
  int elem;

  printf("Bem vindo ao programa de Heap, antes de começar, diga qual vai ser "
         "o tamanho do seu vetor: ");
  scanf(" %d", &total);

  int vet[total];

  while (strcmp(continua, "sim") == 0 || strcmp(continua, "Sim") == 0 ||
         strcmp(continua, "SIM") == 0 || strcmp(continua, "s") == 0 ||
         strcmp(continua, "S") == 0) {

    printf("\n\nEscolha uma das opções abaixo:\n"
           "1 - Adicionar elemento na Heap\n"
           "2 - Remover elemento da Heap\n"
           "3 - Imprimir elementos da Heap\n"
           "4 - Sair\n");
    scanf(" %d", &op);

    switch (op) {

    case (1):
      if (tam == total) {
        printf("Você não pode adicionar mais elementos");
      } else {

        printf("Digite o valor que deseja adicionar: ");
        scanf("%d", &elem);
        Inserir(vet, elem);  
        printf("\nelemento %d foi adicionado ", elem);

        
      }
      break;

    case (2):

      if (tam == 0) {
        printf("Não existem elementos para serem retirados");
      } else {
        res = remover(vet);
     
        printf("\nelemento removido foi %d ", res);
      }

      break;

    case (3):

      printf("Imprimindo os elementos da Heap: ");
      imprimir(vet, tam);

      break;

    case (4):
      printf("\n\nObrigado por utilizar nosso programa!");
      strcpy(continua, "nao");

      break;

    default:
      printf("\nOpção inválida\n");
    }

    if (op != 4) {
      printf("\n\nDeseja continuar?\n\n");
      scanf("%s", continua);
      puts("\n");
    }
  }
}
