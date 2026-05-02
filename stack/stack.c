//Para compilar: gcc -g stack/stack.c lib/valid_input.c -Ilib -o stack/stack
#include "valid_input.h"
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 10;

unsigned int *stack, *pss, *tos;

int errStackOverflow = 0;
int errEmptyStack = 0;
int printPopValue = 0;
unsigned int popValue = 0;

/** Prototipos das Funções */
void push(unsigned int n);
unsigned int pop(void);
void print_stack(void);
void print_stack_exception(void);
void print_validate_exception(TValidateInput validInput);
void print_pop(unsigned int popValue);

int main(void) {

  /*stack aponta para o primeiro elemento da pilha*/
  stack = (unsigned int *)malloc(SIZE * sizeof(unsigned int));
  if (!stack) {
    printf("Erro ao alocar memória!\n");
    return 1;
  }

  pss = stack;     /* pss = ponteiro para o início da pilha */
  tos = stack - 1; /* tos = ponteiro para o topo da pilha */
  
  TValidateInput validInput = {.message = "\0", .isValid = 0, .value = 0};
  char input[50];

  while (1) {

    system("clear");
    printf("*** PILHA de %d elementos: Push e Pop *** \n", SIZE);
    printf("( P ) Retira um valor(Pop)\n");
    printf("( X ) Sair\n\n");

    print_stack_exception();
    print_validate_exception(validInput);
    print_pop(popValue);
    print_stack();

    printf("Digite um número(Push): ");
    scanf("%49s", input);

    if (strlen(input) == 1) {
      char command = toupper(input[0]);
      if (command == 'P') {
        popValue = pop();
        continue;
      }
      if (command == 'X') {
        break; // Sair do loop
      }
    }

    validInput = validate_input(input);
    if (validInput.isValid) {
      push(validInput.value);
    }
  }

  printf("Fim do programa\n");

  free(stack);

  return 0;
}

void push(unsigned int n) {
  if (tos == stack + SIZE - 1) {
    errStackOverflow = 1; // Estouro de pilha
    return;
  }
  tos++;
  *tos = n;
}

unsigned int pop(void) {
  if (tos < pss) {
    errEmptyStack = 1; // Pilha vazia
    return 0;
  }
  unsigned int value = *tos; // Armazena o valor a ser retornado
  tos--;
  printPopValue = 1;
  return value;
}

void print_stack(void) {
  printf("tos->%p\n", (void *)tos);
  printf("pss->%p\n", (void *)pss);
  printf("|%-2s|%-10s|%-20s|\n", "#", "Valor", "Ponteiro");
  printf("-----------------------------------\n");
  unsigned int *i;
  int idx = (tos - pss) + 1;
  for (i = tos; i >= pss; i--) {
    printf("|%2d|%10u|%20p|\n", idx--, *i, (void *)i);
    if (i == pss) break; // para não executar o i-- quando i já for igual a pss, evitando underflow
  }
  printf("\n\n");
}

void print_stack_exception(void) {
  if (errStackOverflow) {
    printf("Estouro de Pilha!\n\n");
    errStackOverflow = 0;
  };
  if (errEmptyStack) {
    printf("Pilha vazia!\n\n");
    errEmptyStack = 0;
  }
}

void print_pop(unsigned int popValue) {
  if (printPopValue) { // Verifica se popValue é o valor que foi retirado
    printf("Retirado: %u->%p\n\n", popValue, tos + 1); // Exibe o valor retirado e o endereço do topo anterior
    printPopValue = 0; // Reseta a flag para evitar mensagens repetidas
  }
}

void print_validate_exception(TValidateInput validInput) {
  if (!validInput.isValid && validInput.message[0] != '\0') {
    printf("%s\n\n", validInput.message);
  }
}