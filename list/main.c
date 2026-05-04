#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>

void clear_screen(void);
void print_menu(void);
void print_list_clubs(void);
void print_sorted_list_clubs(void);
void add_club(void);
void remove_club(void);
void find_club(void);

TClub *list = NULL;

int main(void) {

  char op;

  do {

    clear_screen();
    print_menu();

    scanf("%c", &op);
    getchar();

    if (op == '1') {
      add_club();
    }
    if (op == '2') {
      print_list_clubs();
      getchar();
    }
    if (op == '3') {
      print_sorted_list_clubs();
      getchar();
    }
    if (op == '4') {
      remove_club();
      getchar();
    }
    if (op == '5') {
      find_club();
      getchar();
    }

  } while (op != '0');

  free_list(list);

  return 0;
}

void print_menu(void) {
  int ano = 2026;
  printf("*** Tabela do Brasileirão %d **** \n", ano);

  char menu[][30] = {"1 - Adicionar Clube",        "2 - Exibir Tabela",
                     "3 - Exibir Tabela Ordenada", "4 - Remover Clube",
                     "5 - Pesquisar Clube",        "0 - Sair"};

  char (*m)[30] = menu; // ponteiro para array de 20 chars
  char (*menu_end)[30] = menu + (sizeof(menu) / sizeof(menu[0]));

  while (m < menu_end) {
    printf("%s\n", *m);
    m++;
  }
  printf("> ");
}

void add_club(void) {

  char nome[25];
  int pontos;

  printf("Informe o clube: ");

  fflush(stdin);
  fgets(nome, sizeof(nome), stdin);
  nome[strcspn(nome, "\n")] = '\0';

  printf("Informe os pontos: ");
  scanf("%d", &pontos);
  getchar();

  TClub *new_club = get_new_club(get_next_id(), nome, pontos);

  add_end_dup_linked(new_club, &list);
}

void print_list_clubs(void) {
  if (list) {
    print_list(list);
  } else {
    printf("Lista vazia!");
  }
}

void print_sorted_list_clubs(void) {
  if (list) {
    print_sorted_list(list);
  } else {
    printf("Lista vazia!");
  }
}

void remove_club(void) {
  int id;
  printf("** Remover Clube ** \n");
  printf("Informe o ID: ");
  scanf("%d", &id);
  remove_item_dup_linked(id, &list);
}

void find_club(void) {
  char op;
  printf("** Pesquisar Clube ** \n");
  printf("1 - Por ID | 2 - Por Nome\n");
  printf("> ");

  scanf("%c", &op);
  getchar();

  if (op == '1') {
    int id;
    printf("Informe o ID: ");
    scanf("%d", &id);
    TClub *_find = find_item(id, list);
    if (_find) {
      print_item(_find);
    } else {
      printf("Clube não encontrado\n");
    }
    getchar();
  }

  if (op == '2') {
    char nome[50];
    printf("Informe o nome: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    TClub *_find = find_item_by_name(nome, list);
    if (_find) {
      print_item(_find);
    } else {
      printf("Clube não encontrado\n");
    }
  }
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
