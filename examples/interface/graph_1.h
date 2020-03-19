#ifndef __GRAPH__
#define __GRAPH__

typedef struct {
    int payload;
    int existent;
} Vertex;

typedef struct {
    int from;
    int to;
    int existent;
} Edge;

typedef struct {
    Vertex *vertices;
    int vsize;
    Edge *edges;
    int ecnt;
    int esize;
} Graph;

/*@
  predicate is_vertex(Graph *g, integer v) =
    0 <= v < g->vsize;

  predicate edge_valid(Graph *g, integer k) =
    g->edges[k].existent ==>
    is_vertex(g, g->edges[k].from) &&
    is_vertex(g, g->edges[k].to) &&
    g->vertices[g->edges[k].from].existent &&
    g->vertices[g->edges[k].to].existent;

  predicate edges_valid(Graph *g, integer n) =
    \forall integer k; 0 <= k < n ==> edge_valid(g, k);

  predicate valid(Graph *g) =
    g->vsize > 0 &&
    g->esize > 0 &&
    g->esize >= g->ecnt >= 0 &&
    \valid(g->vertices + (0 .. g->vsize - 1)) &&
    \valid(g->edges + (0 .. g->esize - 1)) &&
    edges_valid(g, g->ecnt) &&
    (\forall integer k; g->ecnt <= k < g->esize ==> !g->edges[k].existent);
*/

//@ predicate edge_saved{L1, L2}(Graph *g, integer k) = \at(g->edges[k], L1) == \at(g->edges[k], L2);
//@ predicate edges_saved{L1, L2}(Graph *g, integer m, integer n) = \forall integer k; m <= k < n ==> edge_saved{L1, L2}(g, k);

/*@ predicate full(Graph *g) = range_existent(g, 0, g->esize);
    predicate range_existent(Graph *g, integer m, integer n) = \forall integer k; m <= k < n ==> g->edges[k].existent;
*/

/*@ axiomatic EdgesCount {
        logic integer count{L}(Graph *g, integer f, integer t, integer m, integer n);
        logic integer all_count(Graph *g, integer f, integer t) = count(g, f, t, 0, g->esize);
        predicate count_saved{L1, L2}(Graph *g, integer f, integer t, integer m, integer n) =
            count{L1}(g, f, t, m, n) == count{L2}(g, f, t, m, n);

        axiom count_zero: \forall Graph *g, integer f, t, m, n; m >= n ==>
            count(g, f, t, m, n) == 0;

        axiom count_one: \forall Graph *g, integer f, t, m;
            count(g, f, t, m, m + 1) == (g->edges[m].existent && g->edges[m].from == f && g->edges[m].to == t ? 1 : 0);

        axiom count_split: \forall Graph *g, integer f, t, m, n, k; m <= n <= k ==>
            count(g, f, t, m, k) == count(g, f, t, m, n) + count(g, f, t, n, k);

        axiom count_saved_ax{L1, L2}: \forall Graph *g, integer f, t, m, n;
            edges_saved{L1, L2}(g, m, n) ==> count_saved{L1, L2}(g, f, t, m, n);
  }
*/

/*@
    ensures \result != 0 ==>
        valid(\result) &&
        \valid(\result) &&
        \freeable(\result) &&
        \freeable(\result->vertices) &&
        \freeable(\result->edges) &&
        \allocable{Pre}(\result) &&
        \allocable{Pre}(\result->vertices) &&
        \allocable{Pre}(\result->edges) &&
        \result->ecnt == 0;
 */
Graph *graph_create(void);

/*@
    requires valid(graph);
    requires \valid(graph);
    requires \freeable(graph);
    requires \freeable(graph->vertices);
    requires \freeable(graph->edges);
    ensures \allocable(graph);
    ensures \allocable(\at(graph->vertices, Pre));
    ensures \allocable(\at(graph->edges, Pre));
*/
void graph_destroy(Graph *graph);

#endif
