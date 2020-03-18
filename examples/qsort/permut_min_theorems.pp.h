// #ifndef __PERMUT_THEOREMS__
// #define __PERMUT_THEOREMS__

// #include "permut.h"
// #include "ordered.h"

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
// 
// #endif
