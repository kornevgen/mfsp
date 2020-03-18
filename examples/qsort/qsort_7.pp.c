// #include "qsort_6.h"
// #include "part_3.h"

// sorts the range ``[l, u]`` of the array ``a``
/*@
    decreases u - l;
 */
void qsort(int *a, int l, int u)
{
    if (u > l) {
        // splits the range into the subranges: [l, m - 1], [m, m] and [m + 1, u]
        int m = partition(a, l, u);
        // assert minimum(a, m, u, a[m]);
        /*@ ghost Lb1:*/

        // sorts the subrange [l, m - 1], not changes the subrange [m, u]
        if (m > l) qsort(a, l, m - 1);
        /*@ assert permutation{Lb1, Here}(a, m, u);*/
        /*@ assert permutation{Lb1, Here}(a, l, m - 1);*/
        /*@ assert permutation{Lb1, Here}(a, l, u);*/
        /*@ assert \forall integer k; l <= k <= m - 1 ==> \at(minimum(a, m, u, a[k]), Lb1);*/
        /*@ assert \forall integer k; l <= k <= m - 1 ==> minimum(a, m, u, a[k]);*/
        /*@ assert \forall integer k; l <= k <= m - 1 ==> minimum(a, k, m - 1, a[k]);*/
        /*@ assert \forall integer k; l <= k <= m - 1 ==> minimum(a, k, u, a[k]);*/

        /*@ ghost Lb2:*/

        // sorts the subrange [m + 1, u], not changes the subrange [l, m]
        if (m < u) qsort(a, m + 1, u);

        /*@ assert permutation{Lb2, Here}(a, m + 1, u);*/
        /*@ assert permutation{Lb2, Here}(a, l, m);*/
        /*@ assert permutation{Lb2, Here}(a, l, u);*/
        /*@ assert \forall integer k; l <= k <= m ==> minimum{Lb2}(a, m + 1, u, \at(a[k], Lb2));*/
        /*@ assert \forall integer k; l <= k <= m ==> minimum(a, m + 1, u, a[k]);*/

        /*@ assert \forall integer k; l <= k <= m ==> minimum(a, k, m, a[k]);*/
        /*@ assert \forall integer k; l <= k <= m ==> minimum(a, k, u, a[k]);*/
        /*@ assert \forall integer k; m + 1 <= k <= u ==> minimum(a, k, u, a[k]);*/
    }
}
