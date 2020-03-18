#ifndef __PERMUT__
#define __PERMUT__

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

#endif
