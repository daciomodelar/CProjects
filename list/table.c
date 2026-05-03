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

void free_list(TClub *list) {
	TClub *aux = list;
	while(aux) {
		TClub * _free = aux;
		printf("Free -> %p\n", _free);
		free(_free);
		aux = aux->next;
	}
}
