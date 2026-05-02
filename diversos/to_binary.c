#include <stdio.h>
#include <string.h>
#include <stdbool.h>

unsigned long toBinario(const unsigned int decimal); // função converte binário versão sem recursividade
unsigned long toBinarioRV1(const unsigned int decimal); // função converte binário recursiva versão 1
unsigned long toBinarioRV2(const unsigned int decimal); // função converte binário recursiva versão 2
unsigned long fatorial(const unsigned int n); //função fatorial versão recursiva
bool isPrimeNumber(const unsigned int n);

void main() {

  int decimal;
  char key;

  do {
    printf("**** Binário | Fatorial | Primo **** \n");
    printf("Informe um número: ");
    scanf("%d", &decimal);
    printf("%d em binário Funcao NRe é: %lu\n", decimal, toBinario(decimal));
    printf("%d em binário Funcao RV1 é: %lu\n", decimal, toBinarioRV1(decimal));
    printf("%d em binário Funcao RV2 é: %lu\n", decimal, toBinarioRV2(decimal));
    printf("%d Fatorial é: %lu\n", decimal, fatorial(decimal));
    printf("%d é Primo: %s\n\n\n", decimal, isPrimeNumber(decimal) ? "Sim" : "Não");
    scanf("%c", &key);

    printf("X para Sair | Enter para continuar\n");
    key = getchar();

    printf("\033[2J\033[H"); // limpa a tela

  } while ((key != 'X') && (key != 'x'));
}

unsigned long toBinario(const unsigned int decimal) {
  unsigned long _binary = 0;
  unsigned long _dec = 1;
  unsigned int _decimal = decimal;
  while (_decimal > 0) {
    unsigned int r = _decimal % 2;
    _binary = (_dec * r) + _binary;
    _dec = _dec * 10;
    _decimal = _decimal / 2;
    //printf("\nbin->%lu\n", _binary);
  }
  return _binary;
}

/**
 * A chamada recursiva usa uma pilha.
 * Na primeira da um push na pilha com o resultado e assim por diante
 * Quando encontra o ponto de conclusão, executa as operações da pilha
 * 
 */
unsigned long toBinarioRV1(const unsigned int decimal) {
    if (decimal == 0) return 0;
    return (decimal % 2) + 10 * toBinarioRV1(decimal/2); 
}

unsigned long toBinarioRV2(const unsigned int decimal) {
    if (decimal == 0) return 0;
    int resto = decimal % 2;
    unsigned long binario = resto + 10 * toBinarioRV2(decimal/2); 
    // printf("dec->%d\n",  decimal);
    // printf("res->%d\n",  resto);
    // printf("bin->%lu\n", binario);
    // printf("%4c\n", '-');
    return binario;
}

unsigned long fatorial(const unsigned int n) {
  if (n > 65) {
    printf ("Fatorial error. Excedeu limite unsigned long\n");
    return 0;
  }
  if (n == 0) {
    return 1; // Caso base: fatorial de 0 é 1
  } else {
    return n * fatorial(n - 1); // Chamada recursiva: calcula fatorial de (n-1)
  }
}

bool isPrimeNumber(const unsigned int n) {
  unsigned int _n = n;
  unsigned int _countDiv = 0;
  while(_n > 0) {
    unsigned int _r = n % _n;
    if (_r == 0) _countDiv++;
    _n--;
  }
  return (_countDiv == 2);
}