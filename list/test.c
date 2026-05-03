#include "table.h"
#include <stdlib.h>
#include <string.h>

int main(void) {

  TClub *list = NULL;

  TClub club1 = {.nome = "Vasco", .pontos = 25};
  TClub club2 = {.nome = "Botafogo", .pontos = 24};
  TClub club3 = {.nome = "Ceara Sport Club", .pontos = 32};
  TClub club4 = {.nome = "Santos", .pontos = 14};

  TClub clubs[4] = {club1, club2, club3, club4};

  TClub *c = clubs;
  TClub *end = clubs + 4;

  while (c < end) {
    TClub *new_club = (TClub *)malloc(sizeof(TClub));
    strcpy(new_club->nome, c->nome);
    new_club->pontos = c->pontos;
    new_club->next = NULL;

    add_start(new_club, &list);

    c++;
  }
  print_list(list);
  sort_list(list);
  print_list(list);
  free_list(list);

  return 0;
}