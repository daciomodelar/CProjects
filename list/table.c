#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <termios.h>
#include <unistd.h>

typedef struct club {
  char nome[20];
  int pontos;
  struct club *next;
} TClub;

void clear_screen(void);

void add(TClub *new_club, TClub **list);
void print_list(TClub *list);
void sort_list(TClub *list);
void sort_list_pointer(TClub *list);

int main(void) {

  char op[10];
  TClub *list = NULL;

  do {

    char nome[20];
    int pontos;

    printf("Clube: ");

    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Pontos: ");
    scanf("%d", &pontos);
    getchar();

    TClub *new_club = (TClub *)malloc(sizeof(TClub));
    strcpy(new_club->nome, nome);
    new_club->pontos = pontos;
    new_club->next = NULL;

    add(new_club, &list);
    clear_screen();
    print_list(list);

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

void add(TClub *new_club, TClub **list) {

  if (!*list) {
    *list = new_club;
  } else {
    TClub *item = *list;
    while (item->next) {
      item = item->next;
    }
    item->next = new_club;
  }
}

void sort_list(TClub *list) {
  if (!list)
    return;

  TClub *current = list;
  while (current) {
    TClub *max_current = current;
    TClub *next = current->next;

    while (next) {
      if (next->pontos > max_current->pontos) {
        max_current = next;
      }
      next = next->next;
    }

    if (max_current != current) {
      char tempNome[20];
      int tempPontos;

      strcpy(tempNome, current->nome);
      tempPontos = current->pontos;

      strcpy(current->nome, max_current->nome);
      current->pontos = max_current->pontos;

      strcpy(max_current->nome, tempNome);
      max_current->pontos = tempPontos;
    }

    current = current->next;
  }
}

void sort_list_pointer(TClub *list) {
  if (!list)
    return;

  TClub *current = list;
  while (current) {
    TClub *max_current = current;
    TClub *next = current->next;

    while (next) {
      if (next->pontos > max_current->pontos) {
        max_current = next;
      }
      next = next->next;
    }

    if (max_current != current) {
      TClub temp = *current;
      *current = *max_current;
      *max_current = temp;

      TClub *tempNext = current->next;
      current->next = max_current->next;
      max_current->next = tempNext;
    }

    current = current->next;
  }
}

void print_list(TClub *list) {
  TClub *aux = list;
  printf("|%-2s|%-20s|%-10s|%-20s|\n", "#", "Clube", "Pontos", "Pointer");
  int pos = 1;
  while (aux) {
    printf("|%-2d|%-20s|%10d|%20p|\n", pos++, aux->nome, aux->pontos,
           (void *)aux);
    aux = aux->next;
  }
  printf("\n");
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
