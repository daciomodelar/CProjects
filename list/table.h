#ifndef TABLE_H
#define TABLE_H

typedef struct club {
  char nome[20];
  int pontos;
  struct club *next;
} TClub;

void add_end(TClub *new_club, TClub **list);
void add_start(TClub *new_club, TClub **list);
void add_sorted(TClub *new_club, TClub **list);
void swap_item(TClub *target, TClub *source);
void print_list(TClub *list);
void sort_list(TClub *list);
void free_list(TClub *list);

#endif