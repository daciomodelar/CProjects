#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void print_stack(TItemStack *topStack) {
  TItemStack *aux = topStack;
  while (aux) {
    printf("%-20s | %2d | %16p | %16p\n", aux->name, aux->count, aux,
           aux->prev);
    aux = aux->prev;
  }
}

void print_item(TItemStack *item) {
  if (!item)
    return;
  printf("%-20s | %2d | %16p\n", item->name, item->count, item->prev);
}
