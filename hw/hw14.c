/***************************************
Этот модуль описывает типы данных для представления
ориентированных графов, их вершин и дуг.

Граф представлен в типе `Graph`.

Поле `vertices` описывает вершины графа. Это массив из `vsize` значений
типа `Vertex`. Тип `Vertex` описывает размещение некоторой вершины графа
в массиве `vertices`. Поле `existent` в элементе массива `vertices` с
некоторым индексом `i` равно истине (т.е. не равно 0) тогда, когда в этом
элементе размещена вершина графа. В противном случае элемент массива
`vertices` с индексом `i` считается свободным.

Поле `edges` описывает дуги графа. Это массив из `esize` значений типа `Edge`.
Тип `Edge` описывает размещение некоторой дуги графа в массиве `edges`.
Поле `existent` в элементе массива `edges` имеет тот же смысл, что и то же
поле в элементе массива `vertices`. Поля `from` и `to` должны быть индексами в
массиве `vertices` и означают вершины, из которой исходит дуга и в которую
входит дуга.

Поле `ecnt` означает то количество первых элементов массива `edges`,
после которого все остальные элементы будут свободными.

Ниже приведено определение описанных типов и предикат `valid`, формально
описывающий инвариант типа `Graph`.

В конце модуля размещена функция `count`, подсчитывающая кратность дуги.
Ее аргумент `g` означает граф, аргументы `f` и `t` означают индексы в
массиве `g->vertices`, означающие начало и конец дуги.
Перед функцией размещена ее формальная спецификация на языке `ACSL`.
****************************************/


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

        axiom count_extend: \forall Graph *g, integer f, t, m, n;
            (\forall integer k; m <= k < n ==> !g->edges[k].existent) ==> count(g, f, t, m, n) == 0;
  }
*/

/*@
    requires \valid(g) && valid(g);
    requires is_vertex(g, f);
    requires is_vertex(g, t);
    requires g->vertices[f].existent;
    requires g->vertices[t].existent;
    ensures \result == all_count(g, f, t);
*/
int
count(Graph *g, int f, int t)
{
    int c = 0;
    for (int i = 0; i < g->ecnt; ++i) {
        if (g->edges[i].existent && g->edges[i].from == f && g->edges[i].to == t) {
            ++ c;
        }
    }
    return c;
}
