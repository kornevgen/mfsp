#ifndef __QUEUE__
#define __QUEUE__

#include <stddef.h>

typedef struct {
    int *buffer;
    size_t start;
    size_t count;
    size_t capacity;
} Queue;

int Queue__initialize(Queue *queue, size_t size);

int Queue__finalize(Queue *queue);

int Queue__enqueue(Queue *queue, int item);

int Queue__dequeue(Queue *queue, int *item);

int Queue__count(Queue *queue);

#endif
