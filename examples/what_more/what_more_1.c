/*@ axiomatic Count {

    logic integer count{L}(int *a, integer i, integer j, integer p);

    axiom base:
        \forall int *a, integer i, j,  p; i >= j ==> count(a, i, j, p) == 0;

    axiom split:
        \forall int *a, integer i, k, j, p; i <= k <= j ==> count(a, i, j, p) == count(a, i, k, p) + count(a, k, j, p);

    axiom one:
        \forall int *a, integer i, p;
            (a[i] == p ==> count(a, i, i+1, p) == 1) &&
            (a[i] != p ==> count(a, i, i+1, p) == 0);
}*/

/*@
    requires n > 0;
    requires \forall integer i; 0 <= i < n ==> \valid(a + i);

    ensures count(a, 0, n, x) > count(a, 0, n, y) ==> \result > 0;
    ensures count(a, 0, n, x) == count(a, 0, n, y) ==> \result == 0;
    ensures count(a, 0, n, x) < count(a, 0, n, y) ==> \result < 0;
*/
int what_more(int a[], int n, int x, int y);
