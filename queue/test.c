#include "queue.h"
#include <stdio.h>
#include <string.h>

// Macro auxiliar para exibir resultado
#define TEST(nome, condicao)                                                   \
  do {                                                                         \
    if (condicao)                                                              \
      printf("✅ PASSOU: %s\n", nome);                                         \
    else                                                                       \
      printf("❌ FALHOU: %s\n", nome);                                         \
  } while (0)

void print_queue(TItemQueue *iniQueue) {
  TItemQueue *aux = iniQueue;
  printf("%-20s | %-6s | %-16s | %-16s\n", "name", "count", "item", "next");
  while (aux) {
    printf("%-20s | %6d | %16p | %16p\n", aux->name, aux->count, aux, aux->next);
    aux = aux->next;
  }
}

void print_item_queue(TItemQueue *item) {
  printf("%-20s | %5d | %16p | %16p\n", item->name, item->count, item,
         item->next);
}

void test_enqueue() {
  printf("***** test enqueue ****\n");

  TItemQueue *iniQueue = NULL;
  TItemQueue *endQueue = NULL;

  TItemQueue *i1 = new_item_queue("Arquivo 1");
  TItemQueue *i2 = new_item_queue("Arquivo 2");
  TItemQueue *i3 = new_item_queue("Arquivo 3");
  TItemQueue *i4 = new_item_queue("Arquivo 4");
  TItemQueue *i5 = new_item_queue("Arquivo 5");

  // caso 1 - Primerio item da fila
  enqueue(i1, &iniQueue, &endQueue);
  TEST("Enqueue primeiro item", (strcmp(iniQueue->name, i1->name) == 0) &&
                                    (strcmp(endQueue->name, i1->name) == 0));

  // caso 2 - Segundo item da fila
  enqueue(i2, &iniQueue, &endQueue);
  TEST("Enqueue segundo item", (strcmp(iniQueue->name, i1->name) == 0) &&
                                   (strcmp(endQueue->name, i2->name) == 0));

  // caso 3 - Terceiro item da fila
  enqueue(i3, &iniQueue, &endQueue);
  TEST("Enqueue terceiro item", (strcmp(iniQueue->name, i1->name) == 0) &&
                                    (strcmp(endQueue->name, i3->name) == 0));
  // caso 4 - Quarto item da fila
  enqueue(i4, &iniQueue, &endQueue);
  TEST("Enqueue quarto item", (strcmp(iniQueue->name, i1->name) == 0) &&
                                  (strcmp(endQueue->name, i4->name) == 0));
  // caso 5 - Fila cheia
  enqueue(i5, &iniQueue, &endQueue);
  TEST("Enqueue em fila cheia", (strcmp(iniQueue->name, i1->name) == 0) &&
                                    (strcmp(endQueue->name, i5->name) != 0));

  print_queue(iniQueue);
  free_queue(iniQueue);
}

void test_dequeue() {
  printf("***** test denqueue ****\n");

  TItemQueue *iniQueue = NULL;
  TItemQueue *endQueue = NULL;

  TItemQueue *i1 = new_item_queue("Arquivo 1");
  TItemQueue *i2 = new_item_queue("Arquivo 2");
  TItemQueue *i3 = new_item_queue("Arquivo 3");
  TItemQueue *i4 = new_item_queue("Arquivo 4");
  enqueue(i1, &iniQueue, &endQueue);
  enqueue(i2, &iniQueue, &endQueue);
  enqueue(i3, &iniQueue, &endQueue);
  enqueue(i4, &iniQueue, &endQueue);

  print_queue(iniQueue);

  // caso 1 - Dequeue primerio item da fila
  TItemQueue *d1 = dequeue(&iniQueue, &endQueue);
  TEST("Dequeue item 1", (strcmp("Arquivo 1", d1->name) == 0));

  // caso 1 - Dequeue primerio item da fila
  TItemQueue *d2 = dequeue(&iniQueue, &endQueue);
  TEST("Dequeue item 2", (strcmp("Arquivo 2", d2->name) == 0));

  print_queue(iniQueue);

  free_queue(iniQueue);
}

int main(void) {
  printf("=============================\n");
  printf("     TESTES - queue.c        \n");
  printf("=============================\n");

  test_enqueue();
  test_dequeue();

  printf("\n===========================\n");
  printf("        FIM DOS TESTES       \n");
  printf("=============================\n");

  return 0;
}