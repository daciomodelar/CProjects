#include "stack.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void push(TItemStack *item, TItemStack **topStack) {

  if (!(*topStack)) {
    *topStack = item;
    return;
  }

  item->prev = *topStack;
  *topStack = item;
}

TItemStack *pop(TItemStack **topStack) {
    if (!(*topStack)) {
        return NULL;
    }
    TItemStack *i = *topStack;
    *topStack = (*topStack)->prev;
    return i;
}

TItemStack *get_new_item(const char *name, const unsigned int code) {

  TItemStack *new_item = (TItemStack *)malloc(sizeof(TItemStack));

  if (!new_item) {
    printf("Erro de alocação de memória");
    return NULL;
  }

  strncpy(new_item->name, name, sizeof(new_item->name) - 1);
  new_item->name[sizeof(new_item->name) - 1] = '\0';
  new_item->code = code;
  new_item->prev = NULL;
  return new_item;
}

void free_stack(TItemStack *topStack) {
  if (!topStack)
    return;
  TItemStack *aux = topStack;
  TItemStack *_free = NULL;
  while (aux->prev) {
    _free = aux;
    aux = aux->prev;
    free(_free);
  }
}