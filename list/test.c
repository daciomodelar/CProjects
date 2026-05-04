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
    TClub *new_club = get_new_club(c->nome, c->pontos);
    add_end(new_club, &list);
    c++;
  }

  print_list(list);
  free_list(list);
  return 0;
}