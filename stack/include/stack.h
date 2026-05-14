#ifndef STACK_H
#define STACK_H

typedef struct item_stack {
    char name[20];
    unsigned int count;
    struct item_stack *prev;
} TItemStack;

void push(TItemStack *item, TItemStack **topStack);
TItemStack* pop(TItemStack **topStack); 
TItemStack* new_item_stack(const char *name);
void free_stack(TItemStack *topStack);

#endif
