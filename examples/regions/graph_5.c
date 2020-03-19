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
    requires \valid(graph);
    requires valid(graph);
    requires 0 <= pos < graph->ecnt;
    requires !graph->edges[pos].existent;
    requires is_vertex(graph, f);
    requires is_vertex(graph, t);
    requires graph->vertices[f].existent;
    requires graph->vertices[t].existent;
    assigns graph->edges[pos];
    allocates \nothing;
    ensures valid(graph);
    ensures graph->edges[pos].existent;
    ensures graph->edges[pos].from == f;
    ensures graph->edges[pos].to == t;
    ensures \forall integer p; 0 <= p < graph->esize ==> p != pos ==> graph->edges[p] == \at(graph->edges[p], Pre);
 */
void insert_edge(Graph *graph, int pos, int f, int t)
{
    graph->edges[pos].existent = 1;
    graph->edges[pos].from = f;
    graph->edges[pos].to = t;
}

/*@
    requires n >= 0;
    requires \valid(graphs + (0 .. n - 1));
    requires 0 <= pos;
    requires \forall integer k; 0 <= k < n ==>
        valid(&graphs[k]) &&
        0 <= pos < graphs[k].ecnt &&
        !graphs[k].edges[pos].existent &&
        is_vertex(&graphs[k], f) &&
        is_vertex(&graphs[k], t) &&
        graphs[k].vertices[f].existent &&
        graphs[k].vertices[t].existent;
*/
void insert_edge_to_graphs(Graph *graphs, int n, int pos, int f, int t)
{
    /*@
        loop invariant \forall integer k; 0 <= k < i ==> graphs[k].edges[pos].existent && graphs[k].edges[pos].from == f && graphs[k].edges[pos].to == t;
        loop invariant 0 <= i <= n;
        loop variant n - i;
     */
    for (int i = 0; i < n; ++i) {
        //@ assert valid(&graphs[i]); // not proved
        //@ assert ! graphs[i].edges[pos].existent; // not proved
        insert_edge(&graphs[i], pos, f, t);
    }
}
