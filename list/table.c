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
void add_start(TClub *new_club, TClub **list);
void print_list(TClub *list);
void sort_list(TClub *list);
TClub *get_sorted_list(TClub *list);

int main(void) {

  char op[10];
  TClub *list = NULL;

  do {
    
		clear_screen();

    char nome[20];
    int pontos;

    printf("Clube: ");

    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Pontos: ");
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

    add_start(new_club, &list);
    print_list(list);
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

void add_start(TClub *new_club, TClub **list) {
  TClub *new = (TClub *)malloc(sizeof(TClub));
  strcpy(new->nome, new_club->nome);
  new->pontos = new_club->pontos;
  if (!*list) {
    *list = new_club;
  } else {
		new->next = *list;
    *list = new;
  }
}

TClub *get_sorted_list(TClub *list) {
	TClub *sorted_list = NULL;
  if (!list)
    return NULL;
	sort_list(list);
  

  return sorted_list;
}

void print_list(TClub *list) {
  printf("List -> %p\n", (void *)list);
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
