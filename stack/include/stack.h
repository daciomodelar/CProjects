#ifndef STACK_H
#define STACK_H

typedef struct item_stack {
    char name[20];
    unsigned int code;
    struct item_stack *prev;
} TItemStack;

void push(TItemStack *item, TItemStack **topStack);
TItemStack* pop(TItemStack **topStack); 
TItemStack *get_new_item(const char *name, const unsigned int code);
void free_stack(TItemStack *topStack);

#endif