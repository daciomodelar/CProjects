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

    if (!(*iniQueue))
        return NULL;

    TItemQueue *removed = malloc(sizeof(TItemQueue));

    if (!removed)
        return NULL;

    // salva os dados do primeiro elemento
    memcpy(removed, *iniQueue, sizeof(TItemQueue));
    removed->next = NULL;

    TItemQueue *current = *iniQueue;

    // desloca os dados dos próximos nós
    while (current->next) {

        strncpy(current->name,
                current->next->name,
                sizeof(current->name) - 1);

        current->name[sizeof(current->name) - 1] = '\0';

        current->count = current->next->count - 1;

        // se o próximo for o último
        if (current->next->next == NULL) {

            TItemQueue *last = current->next;

            current->next = NULL;
            *endQueue = current;

            free(last);

            return removed;
        }

        current = current->next;
    }

    // caso exista apenas um elemento
    free(*iniQueue);

    *iniQueue = NULL;
    *endQueue = NULL;

    return removed;
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

void swap_item_queue(TItemQueue *_dest, TItemQueue *_src) {
  
  //printf("desc->%s <= src->%s\n", _dest->name, _src->name);

  char *_name = _src->name;
  unsigned int _count = _src->count - 1;

  strncpy(_dest->name, _name, sizeof(_dest->name) - 1);
  _dest->name[sizeof(_dest->name) - 1] = '\0';
  _dest->count = _count;
  
}
