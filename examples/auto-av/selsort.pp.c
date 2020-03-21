/*@ axiomatic Count {
    logic integer count{L}(int *a, integer m, integer n, integer p);

    axiom count_base: \forall int *a, integer m, n, p; m >= n ==>
        count(a, m, n, p) == 0;

    axiom count_split: \forall int *a, integer m, n, k, p; m <= n <= k ==>
        count(a, m, k, p) == count(a, m, n, p) + count(a, n, k, p);

    axiom count_one: \forall int *a, integer m, p;
        count(a, m, m + 1, p) == (a[m] == p ? 1 : 0);
  }*/

/*@ axiomatic Ordered {
    predicate ordered{L}(int *a, integer m, integer n);

    axiom ordered_base: \forall int *a, integer m, n; m >= n ==>
        ordered(a, m, n);

    axiom ordered_split: \forall int *a, integer m, k, n; m <= n <= k ==>
        ordered(a, m, k) <==> ordered(a, m, n) && ordered(a, n, k);

    axiom ordered_two: \forall int *a, integer m;
        ordered(a, m, m + 1) <==> a[m] <= a[m + 1];
  } */

/*@
    predicate array_saved{L1, L2}(int *a1, int *a2, integer m, integer n) =
       \forall integer k; m <= k <= n ==> \at(a1[k], L1) == \at(a2[k], L2);

    predicate count_saved{L1, L2}(int *a1, int *a2, integer m, integer n) =
       \forall integer p; count{L1}(a1, m, n, p) == count{L2}(a2, m, n, p);
*/
// */

/* Old-style lemma:
    lemma count_frame{L1, L2}: \forall int *a, integer m, n;
        array_saved{L1, L2}(a, a, m, n - 1)
        ==> count_saved{L1, L2}(a, a, m, n);
*/

// #include <stdlib.h>

/*@ ghost
  /@
     requires \valid(a1 + (m .. n - 1));
     requires \valid(a2 + (m .. n - 1));
     requires array_saved{Here, Here}(a1, a2, m, n - 1);
     decreases n - m;
     assigns \nothing;
     ensures count_saved{Here, Here}(a1, a2, m, n);
  @/
  void count_frame_proof(int *a1, int *a2, int m, int n)
  {
        if (m < n) {
            count_frame_proof(a1, a2, m + 1, n);
            //@ assert \forall integer p; count(a1, m, n, p) == count(a1, m, m + 1, p) + count(a1, m + 1, n, p);
            //@ assert \forall integer p; count(a2, m, n, p) == count(a2, m, m + 1, p) + count(a2, m + 1, n, p);
        } else {
            // trivial
        }
  }*/
// */

/*@ ghost
  /@
     requires n >= 0;
     requires \valid(a1 + (0 .. n - 1));
     requires \valid(a2 + (0 .. n - 1));
     requires array_saved{Here, Here}(a1, a2, 0, n - 1);
     assigns \nothing;
     ensures \forall integer i, j; 0 <= i <= n && 0 <= j <= n ==> count_saved{Here, Here}(a1, a2, i, j);
  @/
  void count_frame2_proof(int *a1, int *a2, int n)
  {
    int i = 0;
    /@
        loop invariant 0 <= i <= n;
        loop invariant \forall integer k, j; 0 <= k < i && 0 <= j <= n ==> count_saved{Here, Here}(a1, a2, k, j);
        loop variant n - i;
     @/
    while (1) {

        int j = 0;
        /@
            loop invariant 0 <= j <= n;
            loop invariant \forall integer k; 0 <= k < j ==> count_saved{Here, Here}(a1, a2, i, k);
            loop variant n - j;
        @/
        while (1) {

            count_frame_proof(a1, a2, i, j);

            if (j == n) {
                break;
            } else {
                ++ j;
            }
        }


        if (i == n) {
            break;
        } else {
            ++i;
        }
    }
  }*/
// */

/*@
  ghost
  /@ requires n >= 0;
     requires \valid(a1 + (0 .. n - 1));
     requires \valid(a2 + (0 .. n - 1));
     decreases n;
     assigns a2[0 .. n - 1];
     ensures array_saved{Pre, Here}(a1, a2, 0, n - 1);
  @/
  void copy_array(int *a1, int *a2, int n)
  {
    if (n == 0) {
        // trivial
    } else {
        a2[n - 1] = a1[n - 1];
        copy_array(a1, a2, n - 1);
    }
  }*/
// */

/*@
    predicate minimum(int *a, integer m, integer n, integer k) =
        \forall integer i; m <= i < n ==> a[k] <= a[i];*/
// */

/*@
    logic integer count_sum(int *a, integer i, integer j, integer n, integer p) =
              count(a, 0, i, p) + count(a, i, i + 1, p) + count(a, i + 1, j, p) + count(a, j, j + 1, p) + count(a, j + 1, n, p);

    lemma count_splitted:
        \forall int *a, integer i, integer j, integer n; 0 <= i <= i + 1 <= j <= j + 1 <= n ==>
       \forall integer p;
              count(a, 0, n, p) == count(a, 0, i, p) + count(a, i, n, p) &&
              count(a, i, n, p) == count(a, i, i + 1, p) + count(a, i + 1, n, p) &&
              count(a, i + 1, n, p) == count(a, i + 1, j, p) + count(a, j, n, p) &&
              count(a, j, n, p) == count(a, j, j + 1, p) + count(a, j + 1, n, p) &&
              count(a, i + 1, n, p) == count(a, i + 1, j, p) + count(a, j, j + 1, p) + count(a, j + 1, n, p) &&
              count(a, i, n, p) == count(a, i, i + 1, p) + count(a, i + 1, j, p) + count(a, j, j + 1, p) + count(a, j + 1, n, p) &&
              count(a, 0, n, p) == count(a, 0, i, p) + count(a, i, i + 1, p) + count(a, i + 1, j, p) + count(a, j, j + 1, p) + count(a, j + 1, n, p) &&
              count(a, 0, n, p) == count_sum(a, i, j, n, p);
 */

/*@
    lemma count_saved_refl{L}:
        \forall int *a, integer m, n; count_saved{L, L}(a, a, m, n);
    lemma count_saved_comm{L1, L2}:
        \forall int *a, *b, integer m, n; count_saved{L1, L2}(a, b, m, n) ==> count_saved{L2, L1}(b, a, m, n);
    lemma count_saved_trans{L1, L2, L3}:
        \forall int *a, *b, *c, integer m, n; count_saved{L1, L2}(a, b, m, n) && count_saved{L2, L3}(b, c, m, n) ==> count_saved{L1, L3}(a, c, m, n);*/
// */

/*@
  requires n >= 0;
  requires \valid(a + (0 .. n-1));
  ensures ordered(a, 0, n - 1);
  ensures count_saved{Pre, Here}(a, a, 0, n);*/
// */
void sort(int *a, int n);

void sort(int *a, int n)
{
    /*@
        loop invariant ordered(a, 0, i - 1);
        loop invariant i > 0 ==> minimum(a, i, n, i - 1);
        loop invariant count_saved{Pre, Here}(a, a, 0, n);
        loop invariant 0 <= i <= n;
        loop variant n - i;
    */
    for (int i = 0; i < n; ++i) {

        int min_pos = i;
        /*@
            loop invariant minimum(a, i, j, min_pos);
            loop invariant i <= min_pos < n;
            loop invariant i + 1 <= j <= n;
            loop variant n - j;
        */
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_pos]) {
                min_pos = j;
            }
        }
        if (min_pos != i) {
            /*@ assert \forall integer p; count_sum(a, i, min_pos, n, p) == count_sum(a, i, min_pos, n, p); // trigger for lemma count_splitted
*/            /*@ ghost int *aLiter = malloc(n * sizeof *aLiter); copy_array(a, aLiter, n); */
            /*@ assert \forall integer p; count_sum(aLiter, i, min_pos, n, p) == count_sum(aLiter, i, min_pos, n, p); // trigger for lemma count_splitted
*/            /*@ ghost count_frame2_proof(a, aLiter, n);*/
            int tmp = a[min_pos];
            a[min_pos] = a[i];
            a[i] = tmp;
            /*@ ghost count_frame_proof(a, aLiter, 0, i);*/
            /*@ ghost count_frame_proof(a, aLiter, i + 1, min_pos);*/
            /*@ ghost count_frame_proof(a, aLiter, min_pos + 1, n);*/
            /*@ assert \forall integer p; count(a, min_pos, min_pos + 1, p) == count(aLiter, i, i + 1, p) && count(aLiter, min_pos, min_pos + 1, p) == count(a, i, i + 1, p);*/
            /*@ assert \forall integer p; count(a, 0, n, p) == count_sum(a, i, min_pos, n, p) == count_sum(aLiter, i, min_pos, n, p) == count(aLiter, 0, n, p);*/
        }
    }
}
