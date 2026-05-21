#ifndef QUEUE_H
#define QUEUE_H

typedef struct item_queue {
    char name[20];
    unsigned int count;
    struct item_queue *next;
} TItemQueue;

void enqueue(TItemQueue *new_item, TItemQueue **iniQueue, TItemQueue **endQueue);
TItemQueue* dequeue(TItemQueue **iniQueue, TItemQueue **endQueue);
TItemQueue *new_item_queue(const char *name);
void free_queue(TItemQueue *iniQueue);

#endif
