#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_end(TClub *new_club, TClub **list) {
  if (!*list) {
    *list = new_club;
    return;
  }
  TClub *item = *list;
  while (item->next) {
    item = item->next;
  }
  item->next = new_club;
}

void add_start(TClub *new_club, TClub **list) {
  if (!*list) {
    *list = new_club;
    return;
  }
  new_club->next = *list;
  *list = new_club;
}

void add_sorted(TClub *new_club, TClub **list) {
  TClub *p = *list;
  TClub *old = NULL;

  while (p && new_club->pontos <= p->pontos) {
    old = p;
    p = p->next;
  }

  if (old == NULL) {
    new_club->next = *list;
    *list = new_club;
  } else {
    new_club->next = p;
    old->next = new_club;
  }
}

void swap_item(TClub *_target, TClub *_source) {
  TClub temp = *_source;
  *_source = *_target;
  *_target = temp;

  TClub *tempNext = _target->next;
  _target->next = _source->next;
  _source->next = tempNext;
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
      swap_item(current, max_current);
    }

    current = current->next;
  }
}

void print_list(TClub *list) {

  TClub *aux = list;

  printf("Pointer Table -> %p\n", (void *)aux);

  printf("|%-2s|%-25s|%-10s|%-20s|\n", "#", "Clube", "Pontos", "Pointer");
  printf("--------------------------------------------------------------\n");

  short int pos = 1;

  while (aux) {

    printf("|%2d|", pos++);

    printf("%-25s|", aux->nome);

    printf("%10d|", aux->pontos);

    printf("%20p|\n", (void *)aux);

    aux = aux->next;
  }
}

void free_list(TClub *list) {
  TClub *aux = list;
  TClub *_free = NULL;
  while (aux) {
    _free = aux;
    // printf("free->%p\n",_free);
    // printf("free_content1->%s\n",_free->nome);
    free(_free);
    // printf("free_content2->%s\n",_free->nome);
    aux = aux->next;
  }
}

TClub *get_new_club(char *nome, int pontos) {
  TClub *new_club = (TClub *)malloc(sizeof(TClub));
  if (!new_club) {
    printf("Erro de memória");
    return NULL;
  }
  strcpy(new_club->nome, nome);
  new_club->pontos = pontos;
  new_club->next = NULL;
  return new_club;
}