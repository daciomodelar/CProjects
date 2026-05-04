#include "table.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  TClub clubs[] = {
      {.nome = "Vasco", .pontos = 59},
      {.nome = "Ceará", .pontos = 45},
      {.nome = "Palmeiras", .pontos = 68},
      {.nome = "São Paulo", .pontos = 55},
      {.nome = "Botafogo", .pontos = 61},
      {.nome = "Fluminense", .pontos = 58},
      {.nome = "Grêmio", .pontos = 64},
      {.nome = "Internacional", .pontos = 52},
      {.nome = "Atlético Mineiro", .pontos = 66},
      {.nome = "Flamengo", .pontos = 28},
      {.nome = "Cruzeiro", .pontos = 47},
      {.nome = "Bahia", .pontos = 50},
      {.nome = "Fortaleza", .pontos = 57},
      {.nome = "Corinthians", .pontos = 49},
      {.nome = "Athletico Paranaense", .pontos = 59},
      {.nome = "Bragantino", .pontos = 54},
      {.nome = "Juventude", .pontos = 38},
      {.nome = "Goiás", .pontos = 41},
      {.nome = "Coritiba", .pontos = 36},
      {.nome = "América Mineiro", .pontos = 44},
  };

  int _length = sizeof(clubs) / sizeof(clubs[0]);
  TClub *c = clubs;
  TClub *end = clubs + _length;

  TClub *list = NULL;

  while (c < end) {
    sanitize_string(c->nome);
    TClub *new_club = get_new_club(get_next_id(), c->nome, c->pontos);
    add_end_dup_linked(new_club, &list);
    c++;
  }

  print_list(list);
  printf("\n\n");
  print_sorted_list(list);
  printf("\n\n");
  TClub *aux = list;
  while (aux) {
    if (aux->id % 2 > 0) {
      TClub *_item = find_item(aux->id, list);
      remove_item_dup_linked(_item, &list);
    }
    aux = aux->next;
  }
  print_list_pointer(list);
  printf("\n\n");

  // TClub *_find = find_item(6, list);
  //  print_item(_find->prev);
  //  print_item(_find);
  //  print_item(_find->next);

  // TClub *_item1 = find_item(1, list);
  // TClub *_item2 = find_item(2, list);
  // TClub *_item3 = find_item(3, list);
  // TClub *_item4 = find_item(4, list);

  // remove_item_dup_linked(_item1, &list);
  // //remove_item_dup_linked(_item4, &list);
  // remove_item_dup_linked(_item3, &list);

  // print_list_pointer(list);

  // TClub *aux = list;
  // while (aux) {
  //   if (aux->id % 2 > 0) {
  //     remove_item(aux->id, &list);
  //   }
  //   aux = aux->next;
  // }

  // print_list(list);

  free_list(list);

  return 0;
}