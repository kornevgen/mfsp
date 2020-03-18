#ifndef __ORDERED__
#define __ORDERED__

/*@
    predicate ordered{L}(int *a, integer n, integer m) =
        \forall integer k; n <= k <= m ==> minimum(a, k, m, a[k]);

    predicate minimum{L}(int *a, integer n, integer m, integer p) =
        \forall integer k; n <= k <= m ==> p <= a[k];
*/

#endif
