// #include "qsort_1.h"
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

        // sorts the subrange [l, m - 1], not changes the subrange [m, u]
        if (m > l) qsort(a, l, m - 1);

        // sorts the subrange [m + 1, u], not changes the subrange [l, m]
        if (m < u) qsort(a, m + 1, u);
    }
}
