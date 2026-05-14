#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned int MAX = 4;

void enqueue(TItemQueue *new_item, TItemQueue **iniQueue,
             TItemQueue **endQueue) {

  if (!(*iniQueue)) {
    new_item->count = 1;
    *iniQueue = new_item;
    *endQueue = new_item;
    return;
  }

  if (((*endQueue)->count + 1) > MAX)
    return;

  new_item->count = (*endQueue)->count + 1;
  (*endQueue)->next = new_item;

  *endQueue = new_item;
}

TItemQueue *dequeue(TItemQueue **iniQueue, TItemQueue **endQueue) {

  TItemQueue *aux = *iniQueue;

  while (aux->next) {
    swap_item_queue(aux, aux->next);
    aux = aux->next;
  }
  
  // *endQueue = aux;
  // free(*endQueue);

  return *iniQueue;
}

TItemQueue *new_item_queue(const char *name) {

  TItemQueue *new_item = (TItemQueue *)malloc(sizeof(TItemQueue));

  if (!new_item) {
    printf("Erro de alocação de memória");
    return NULL;
  }

  strncpy(new_item->name, name, sizeof(new_item->name) - 1);
  new_item->name[sizeof(new_item->name) - 1] = '\0';
  new_item->next = NULL;
  return new_item;
}

void free_queue(TItemQueue *iniQueue) {
  if (!iniQueue)
    return;
  TItemQueue *aux = iniQueue;
  TItemQueue *_free = NULL;
  while (aux) {
    _free = aux;
    aux = aux->next;
    free(_free);
  }
}

void swap_item_queue(TItemQueue *dest, TItemQueue *src) {
  char *_name = src->name;
  unsigned int _count = src->count - 1;
  strncpy(dest->name, _name, sizeof(dest->name) - 1);
  dest->name[sizeof(dest->name) - 1] = '\0';
  dest->count = _count;
}
