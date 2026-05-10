#include "stack.h"
#include <stdio.h>
#include <string.h>

const unsigned int MAX = 3;

TItemStack *topStack = NULL;

// Macro auxiliar para exibir resultado
#define TEST(nome, condicao)                                                   \
  do {                                                                         \
    if (condicao)                                                              \
      printf("✅ PASSOU: %s\n", nome);                                         \
    else                                                                       \
      printf("❌ FALHOU: %s\n", nome);                                         \
  } while (0)

void print_stack(TItemStack *topStack) {
  TItemStack *aux = topStack;
  while (aux) {
    printf("%-20s | %5d | %16p\n", aux->name, aux->code, aux->prev);
    aux = aux->prev;
  }
}

void test_new_item(TItemStack *item) {
  int _b = (strcmp(item->name, "Soma") == 0) && (item->code == 1156) && (item->prev == NULL);  
  TEST("New Item", _b);
}

void test_push(TItemStack *i1, TItemStack *i2, TItemStack *i3) {

  push(i1, &topStack);
  push(i2, &topStack);
  push(i3, &topStack);

  TEST("Push Item 1", topStack->code == i3->code);
  TEST("Push Item 2", topStack->prev->code == i2->code);
  TEST("Push Item 3", topStack->prev->prev->code == i1->code);

  free_stack(topStack);
}

void test_pop(void) {

  TItemStack *pop1 = pop(&topStack);
  TItemStack *pop2 = pop(&topStack);

  TEST("Pop Item 1 code 903", pop1->code == 903);
  TEST("Pop Prev Item 1 code 2001", pop1->prev->code == 2001);

  TEST("Pop Item 2 code 2001", pop2->code == 2001);
  TEST("Pop Prev Item 1 code 1156", pop2->prev->code == 1156);

  free_stack(topStack);
}

int main(void) {

  TItemStack *i1 = get_new_item("Soma", 1156);
  TItemStack *i2 = get_new_item("Multiplicacao", 2001);
  TItemStack *i3 = get_new_item("Subtracao", 903);

  test_new_item(i1);   
  
  test_push(i1, i2, i3);

  test_pop();

  return 0;
}