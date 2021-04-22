#include "queue.h"

#define EIFNZ(expr) do { if ((expr) != 0) goto FINALLY; } while (0)

void test1(void)
{
    Queue q; size_t c; int it;
    if (Queue__initialize(&q, 10) != 0) return;

    EIFNZ(Queue__enqueue(&q, 42));
    c = Queue__count(&q);
    //@ assert c == 1;

    EIFNZ(Queue__enqueue(&q, 422));
    c = Queue__count(&q);
    //@ assert c == 2;

    EIFNZ(Queue__dequeue(&q, &it));
    c = Queue__count(&q);
    //@ assert it == 42;
    //@ assert c == 1;

    EIFNZ(Queue__dequeue(&q, &it));
    c = Queue__count(&q);
    //@ assert it == 422;
    //@ assert c == 0;

    int r = Queue__dequeue(&q, &it);
    //@ assert r != 0;

FINALLY:
    Queue__finalize(&q);
}

void test2(void)
{
    Queue q[2]; size_t c; int it;
    if (Queue__initialize(&q[0], 10) != 0) return;
    if (Queue__initialize(&q[1], 10) != 0) {
        Queue__finalize(&q[0]);
        return;
    }

    EIFNZ(Queue__enqueue(&q[0], 42));
    c = Queue__count(&q[0]);
    //@ assert c == 1;
    c = Queue__count(&q[1]);
    //@ assert c == 0;

    EIFNZ(Queue__enqueue(&q[1], 422));
    c = Queue__count(&q[0]);
    //@ assert c == 1;
    c = Queue__count(&q[1]);
    //@ assert c == 1;

    EIFNZ(Queue__dequeue(&q[0], &it));
    c = Queue__count(&q[0]);
    //@ assert it == 42;
    //@ assert c == 0;
    c = Queue__count(&q[1]);
    //@ assert c == 1;

    EIFNZ(Queue__dequeue(&q[1], &it));
    c = Queue__count(&q[0]);
    //@ assert it == 422;
    //@ assert c == 0;
    c = Queue__count(&q[1]);
    //@ assert c == 0;

FINALLY:
    Queue__finalize(&q[0]);
    Queue__finalize(&q[1]);
}

int main(void)
{
    test1();
    test2();
}
