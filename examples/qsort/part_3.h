#ifndef __PARTITION__
#define __PARTITION__

#include "permut.h"
#include "ordered.h"

// splits the range [l, u] into 3 subranges: [l, m), {m}, (m, u].
// all items from [l, m) are less or equal to the m'th item.
// all items from (m, u] are greater or equal to the m'th item.

/*@
    requires u >= l + 1;
    requires \valid(a + (l .. u));
    ensures permutation{Pre, Post}(a, l, u);
    ensures l <= \result <= u;
    ensures \forall integer k; l <= k <= \result - 1 ==> minimum(a, \result, u, a[k]);
    ensures minimum(a, \result + 1, u, a[\result]);
 */
int partition(int *a, int l, int u);

#endif
