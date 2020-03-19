#include "graph_1.h"

void test1(void)
{
    Graph *g = graph_create();
    if (!g) return;
    graph_destroy(g);
    //@ assert \allocable(g->vertices);
    //@ assert \freeable(g->vertices);
    //@ assert 0 != 0;
}
