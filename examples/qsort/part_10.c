#include "part_8.h"

/*@
    requires \valid(a + i);
    requires \valid(a + j);
    assigns a[i], a[j];
    ensures Swap{Pre, Post}(a, i, j);
 */
void swap(int *a, int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int partition(int *a, int l, int u) {
    int m = l, i = l;
    // array is splitted into the following areas:
    // - a[l] is a pivot
    // - a[l+1 .. m] is items which is less than the pivot
    // - a[m+1 .. i] is items which is not less than the pivot
    /*@
        loop invariant permutation{Pre, Here}(a, l, u);
        loop invariant l <= m <= i;
        loop invariant l <= i <= u;
        loop invariant \forall integer k; l <= k <= m ==> minimum(a, m + 1, i, a[k]);
        loop invariant \forall integer k; l + 1 <= k <= m ==> minimum(a, l, l, a[k]);
        loop invariant minimum(a, m + 1, i, a[l]);
        loop assigns a[l .. i];
        loop variant u - i;
     */
    while (i < u) {
        ++i;
        if (a[i] < a[l]) {
            swap(a, ++m, i);
        }
    }
    //@ assert minimum(a, l, l, a[m]);
    //@ ghost L1:
    swap(a, l, m);
    //@ assert permutation{Here, L1}(a, l, m);
    //@ assert permutation{Here, L1}(a, m + 1, u);
    //@ assert minimum(a, m + 1, i, a[m]);
    //@ assert minimum(a, m, m, a[l]);
    //@ assert \forall integer k; l + 1 <= k <= m - 1 ==> minimum(a, m, m, a[k]);
    //@ assert \forall integer i; l <= i <= m ==> minimum{L1}(a, m + 1, u, \at(a[i],L1));
    //@ assert \forall integer i; l <= i <= m ==> minimum(a, m + 1, u, a[i]);
    //@ assert \forall integer i; l <= i <= m - 1 ==> minimum(a, m + 1, u, a[i]);
    //@ assert \forall integer i; l <= i <= m - 1 ==> minimum(a, m, m, a[i]);
    //@ assert \forall integer i; l <= i <= m - 1 ==> minimum(a, m, u, a[i]);
    return m;
}
