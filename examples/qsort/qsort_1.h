#ifndef __QSORT__
#define __QSORT__

#include "ordered.h"
#include "permut.h"

// sorts the range ``[l, u]`` of the array ``a``
/*@
    requires \valid(a + (l .. u));
    ensures ordered(a, l, u);
    ensures permutation{Pre, Post}(a, l, u);
 */
void qsort(int *a, int l, int u);

#endif
