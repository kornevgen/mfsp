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

/*@ lemma max_count_value:
        \forall int *a, integer i, j, p; i <= j ==> 0 <= count(a, i, j, p) <= j - i;
*/

/*@
    requires n > 0;
    requires \forall integer i; 0 <= i < n ==> \valid(a + i);

    ensures count(a, 0, n, x) > count(a, 0, n, y) ==> \result > 0;
    ensures count(a, 0, n, x) == count(a, 0, n, y) ==> \result == 0;
    ensures count(a, 0, n, x) < count(a, 0, n, y) ==> \result < 0;
*/
int what_more(int a[], int n, int x, int y) {

    if (x == y) {
        return 0;
    }

    int c_x = 0, c_y = 0, i;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant c_x == count(a, 0, i, x);
        loop invariant c_y == count(a, 0, i, y);
        loop variant n - i;
    */
    for (i = 0; i < n; ++i) {
        if (a[i] == x) {
            ++ c_x;
        } else if (a[i] == y) {
            ++ c_y;
        }
        //@ assert count(a, 0, i + 1, x) == count(a, 0, i, x) + count(a, i, i+1, x);
        //@ assert count(a, 0, i + 1, y) == count(a, 0, i, y) + count(a, i, i+1, y);
        //@ assert count(a, 0, n, x) == count(a, 0, i + 1, x) + count(a, i + 1, n, x);
        //@ assert count(a, 0, n, y) == count(a, 0, i + 1, y) + count(a, i + 1, n, y);
        if (c_x > c_y + (n - i - 1)) return 1;
        if (c_y > c_x + (n - i - 1)) return -1;
    }

    return c_x - c_y;
}
