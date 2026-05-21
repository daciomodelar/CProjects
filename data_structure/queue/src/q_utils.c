#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void print_queue(TItemQueue *iniQueue) {
  TItemQueue *aux = iniQueue;
  printf("%-20s | %-6s | %-16s | %-16s\n", "Name", "Count", "Address", "Next");
  while (aux) {
    printf("%-20s | %6d | %16p | %16p\n", aux->name, aux->count, aux, aux->next);
    aux = aux->next;
  }
  printf("\n");
}

void print_item_queue(TItemQueue *item) {
  printf("%-20s | %5d | %16p | %16p\n", item->name, item->count, item,
         item->next);
}
