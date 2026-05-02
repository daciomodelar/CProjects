#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

unsigned int *tos, *p1;
unsigned int *stack = NULL;
typedef struct ValidateInput {
  char message[100];
  int code;
} TValidateInputReturn;

int errStackOverflow = 0;
int errEmptyStack = 0;
TValidateInputReturn validInput = {"Entrada válida", 200};
int printPop = 0;

/** Prototipos das Funções */
void push(unsigned int n);
unsigned int pop(void);
void print_stack(void);
void print_exception(void);
void print_pop(unsigned int popValue);
TValidateInputReturn validate_input(const char *input);

int main(void) {

  unsigned int value = 0;
  char *p = NULL, input[50];
  int opc = 0;
  unsigned int popValue = 0;

  /*stack aponta para o primeiro elemento da pilha*/
  stack = (unsigned int *)malloc(SIZE * sizeof(unsigned int));
  if (!stack) {
    printf("Erro ao alocar memória!\n");
    return 1;
  }

  tos = stack;    /* tos aponta para o início da pilha */
  p1 = stack - 1; /* p1 aponta para o topo da pilha (vazia: antes do início) */

  do {

    system("clear");
    printf("*** Pilha de %d elementos: Push e Pop *** \n", SIZE);
    printf("( D ) Retira um valor(Pop)\n");
    printf("( E ) Sair\n\n");

    print_exception();
    print_pop(popValue);
    print_stack();

    printf("Digite um número: ");
    scanf("%s", input);

    validInput = validate_input(input);

    if (validInput.code == 200) {

      value = strtol(input, &p, 10);

      if (toupper(input[0]) == 'D') {
        popValue = pop();
        printPop = 1;
      }

      if (value >= 0 && strlen(p) == 0) {
        push(value);
      }
    }

  } while (toupper(input[0]) != 'E');

  printf("Fim do programa\n");

  free(stack);

  return 0;
}

void push(unsigned int n) {
  if (p1 - tos + 1 >= SIZE) {
    errStackOverflow = 1; // Estouro de pilha
    return;
  }
  p1++;
  *p1 = n;
}

unsigned int pop(void) {
  if (p1 < tos) {
    errEmptyStack = 1; // Pilha vazia
    return 0;
  }
  unsigned int val = *p1;
  p1--;
  return val;
}

void print_stack(void) {
  printf("|%-2s|%-10s|%-20s|\n", "#", "Valor", "Ponteiro");
  printf("-----------------------------------\n");
  unsigned int *i;
  int idx = 0;
  for (i = p1; i >= tos; i--) {
    printf("|%2d|%10u|%20p|\n", ++idx, *i, i);
  }
  printf("\n\n");
}

void print_exception(void) {
  if (errStackOverflow) {
    printf("Estouro de Pilha!\n\n");
    errStackOverflow = 0;
  };
  if (errEmptyStack) {
    printf("Pilha vazia!\n\n");
    errEmptyStack = 0;
    printPop = 0;
  }
  if (validInput.code != 200) {
    printf("%s!\n\n", validInput.message);
  }
}

void print_pop(unsigned int popValue) {
  if (printPop) {
    printf("Retirado: %u->%p\n\n", popValue, (p1 + 1));
    printPop = 0;
  }
}

TValidateInputReturn validate_input(const char *input) {

  if (input == NULL || *input == '\0') {
    TValidateInputReturn return_validate = {"Valor informado é inválido", 400};
    return return_validate;
  }

  if (strlen(input) == 1) {
    if (toupper(input[0]) == 'D' || toupper(input[0]) == 'E') {
      TValidateInputReturn return_validate = {"Entrada válida", 200};
      return return_validate;
    }
  }

  char *ptr = NULL;
  ptr = (char *)input;
  while (*ptr) { // Enquanto o caractere atual não for o terminador nulo
    if ((ptr == input) && (*ptr == '-' || *ptr == '+')) {
      ptr++; // Move para o próximo caractere
    }
    if (!isdigit(*ptr)) {
      TValidateInputReturn return_validate = {"Entrada inválida", 400};
      return return_validate; // Se o caractere não for um dígito, retorna falso
    }
    ptr++; // Move para o próximo caractere
  }

  long value = strtol(input, NULL, 10);
  if (value < 0 || value > UINT_MAX) {
    TValidateInputReturn result;
    snprintf(result.message, sizeof(result.message), "Fora do intervalo : 0 a %u", UINT_MAX);
    result.code = 400;
    return result;
  }

  TValidateInputReturn return_validate = {"Entrada válida", 200};
  return return_validate; // Entrada válida
}
