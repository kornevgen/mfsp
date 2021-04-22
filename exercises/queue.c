#include "queue.h"
#include <stdlib.h>

int Queue__initialize(Queue *queue, size_t size)
{
    queue->buffer = malloc(sizeof (int [size]));
    if (queue->buffer == 0) {
        return 1;
    }
    queue->start = queue->count = 0;
    queue->capacity = size;
    return 0;
}

int Queue__finalize(Queue *queue)
{
    free(queue->buffer);
    return 0;
}

int Queue__enqueue(Queue *queue, int item)
{
    if (queue->start + queue->count >= queue->capacity) {
        return 1;
    }
    queue->buffer[queue->start + queue->count] = item;
    ++ queue->count;
    return 0;
}

int Queue__dequeue(Queue *queue, int *item)
{
    if (queue->count == 0) {
        return 1;
    }
    *item = queue->buffer[queue->start];
    -- queue->count;
    if (queue->count == 0) {
        queue->start = 0;
    } else {
        ++ queue->start;
    }
    return 0;
}

int Queue__count(Queue *queue)
{
    return queue->count;
}
