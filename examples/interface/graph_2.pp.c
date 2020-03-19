// #include "graph_1.h"
// #include <stdlib.h>

Graph *graph_create(void)
{
    Graph *g = malloc(sizeof *g);
    if (!g) {
        return 0;
    }
    g->vsize = 1024;
    g->vertices = malloc(g->vsize * sizeof *g->vertices);
    if (!g->vertices) {
        free(g);
        return 0;
    }
    g->esize = 1024;
    g->ecnt = 0;
    g->edges = malloc(g->esize * sizeof *g->edges);
    if (!g->edges) {
        free(g->vertices);
        free(g);
        return 0;
    }
    /*@
        loop invariant \forall integer k; 0 <= k < i ==> !g->vertices[k].existent;
        loop invariant 0 <= i <= g->vsize;
        loop variant g->vsize - i;
    */
    for (int i = 0; i < g->vsize; ++i) {
        g->vertices[i].existent = 0;
    }
    /*@
        loop invariant \forall integer k; 0 <= k < i ==> !g->edges[k].existent;
        loop invariant 0 <= i <= g->esize;
        loop variant g->esize - i;
    */
    for (int i = 0; i < g->esize; ++i) {
        g->edges[i].existent = 0;
    }
    return g;
}

void graph_destroy(Graph *graph)
{
    free(graph->edges);
    free(graph->vertices);
    free(graph);
}
