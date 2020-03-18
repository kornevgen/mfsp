/*@
    predicate ordered{L}(int *a, integer n, integer m) =
        \forall integer k; n <= k <= m ==> minimum(a, k, m, a[k]);

    predicate minimum{L}(int *a, integer n, integer m, integer p) =
        \forall integer k; n <= k <= m ==> p <= a[k];
*/

/*@
    inductive permutation{L1,L2}(int *a, integer l, integer h) {
    case Permut_refl{L}:
     \forall int *a, integer l, h; permutation{L,L}(a, l, h) ;
    case Permut_sym{L1,L2}:
      \forall int *a, integer l, h;
        permutation{L1,L2}(a, l, h) ==> permutation{L2,L1}(a, l, h) ;
    case Permut_trans{L1,L2,L3}:
      \forall int *a, integer l, h;
        permutation{L1,L2}(a, l, h) && permutation{L2,L3}(a, l, h) ==>
          permutation{L1,L3}(a, l, h) ;
    case Permut_swap{L1,L2}:
      \forall int *a, integer l, h, i, j;
         l <= i <= h && l <= j <= h && Swap{L1,L2}(a, i, j) ==>
       permutation{L1,L2}(a, l, h) ;
   }

   predicate Swap{L1,L2}(int *a, integer i, integer j) =
        \at(a[i],L1) == \at(a[j],L2)
     && \at(a[j],L1) == \at(a[i],L2)
     && \forall integer k; k != i && k != j ==> \at(a[k],L1) == \at(a[k],L2);
  */

/*@
    lemma permutation_reads{L1, L2}:
        \forall int *a, integer n, m;
            (\forall integer i; n <= i <= m ==> \at(a[i], L1) == \at(a[i], L2)) ==>
            permutation{L1, L2}(a, n, m);
    lemma permutation_saves_min{L1, L2}:
        \forall int *a, integer n, m, s;
            permutation{L1, L2}(a, n, m) ==>
            minimum{L1}(a, n, m, s) ==>
            minimum{L2}(a, n, m, s);
    lemma permutation_saves_many_min{L1, L2}:
        \forall int *a, integer n, m, p, q; (m < p || q < n) ==>
            permutation{L1, L2}(a, p, q) ==>
            permutation{L1, L2}(a, n, m) ==>
            (\forall integer i; n <= i <= m ==> minimum{L1}(a, p, q, \at(a[i],L1))) ==>
            (\forall integer i; n <= i <= m ==> minimum{L2}(a, p, q, \at(a[i],L2)));
    lemma permutation_split{L1, L2}:
        \forall int *a, integer n, m, k; n <= m <= k ==>
            permutation{L1, L2}(a, n, m) && permutation{L1, L2}(a, m + 1, k) ==>
            permutation{L1, L2}(a, n, k);
 */

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

/*@
    requires u >= l + 1;
    requires \valid(a + (l .. u));
    assigns a[l .. u];
    ensures permutation{Pre, Post}(a, l, u);
    ensures l <= \result <= u;
    ensures \forall integer k; l <= k <= \result - 1 ==> minimum(a, \result, u, a[k]);
    ensures minimum(a, \result + 1, u, a[\result]);
 */
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

// sorts the range ``[l, u]`` of the array ``a``
/*@
    requires \valid(a + (l .. u));
    decreases u - l;
    assigns a[l .. u];
    ensures ordered(a, l, u);
    ensures permutation{Pre, Post}(a, l, u);
 */
void qsort(int *a, int l, int u)
{
    if (u > l) {
        // splits the range into the subranges: [l, m - 1], [m, m] and [m + 1, u]
        int m = partition(a, l, u);
        // assert minimum(a, m, u, a[m]);
        //@ ghost Lb1:

        // sorts the subrange [l, m - 1], not changes the subrange [m, u]
        if (m > l) qsort(a, l, m - 1);
        //@ assert permutation{Lb1, Here}(a, m, u);
        //@ assert permutation{Lb1, Here}(a, l, m - 1);
        //@ assert permutation{Lb1, Here}(a, l, u);
        //@ assert \forall integer k; l <= k <= m - 1 ==> \at(minimum(a, m, u, a[k]), Lb1);
        //@ assert \forall integer k; l <= k <= m - 1 ==> minimum(a, m, u, a[k]);
        //@ assert \forall integer k; l <= k <= m - 1 ==> minimum(a, k, m - 1, a[k]);
        //@ assert \forall integer k; l <= k <= m - 1 ==> minimum(a, k, u, a[k]);

        //@ ghost Lb2:

        // sorts the subrange [m + 1, u], not changes the subrange [l, m]
        if (m < u) qsort(a, m + 1, u);

        //@ assert permutation{Lb2, Here}(a, m + 1, u);
        //@ assert permutation{Lb2, Here}(a, l, m);
        //@ assert permutation{Lb2, Here}(a, l, u);
        //@ assert \forall integer k; l <= k <= m ==> minimum{Lb2}(a, m + 1, u, \at(a[k], Lb2));
        //@ assert \forall integer k; l <= k <= m ==> minimum(a, m + 1, u, a[k]);

        //@ assert \forall integer k; l <= k <= m ==> minimum(a, k, m, a[k]);
        //@ assert \forall integer k; l <= k <= m ==> minimum(a, k, u, a[k]);
        //@ assert \forall integer k; m + 1 <= k <= u ==> minimum(a, k, u, a[k]);
    }
}
