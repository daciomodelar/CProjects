#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>

void clear_screen(void);

int main(void) {

  char op[10];
  TClub *list = NULL;

  do {

    char nome[20];
    int pontos;

    clear_screen();
    print_list(list);

    printf("Informe o clube: ");

    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Informe os pontos: ");
    scanf("%d", &pontos);
    getchar();

    TClub *new_club = (TClub *)malloc(sizeof(TClub));

    if (!new_club) {
      printf("Erro de memória");
      return 1;
    }

    strcpy(new_club->nome, nome);
    new_club->pontos = pontos;
    new_club->next = NULL;

    add_sorted(new_club, &list);

    // TClub *s_list = get_sorted_list(list);
    // print_list(s_list);

    printf("0 - Sair\n1 - Continuar\n> ");
    fgets(op, sizeof(op), stdin);

    if (op[0] == '0') {
      printf("Saindo...\n");
    } else if (op[0] == '1') {
      printf("Continuando...\n");
    }

  } while (op[0] != '0');

  free(list);

  return 0;
}

void clear_screen(void) {
  struct termios oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  printf("\033[H\033[J");
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
