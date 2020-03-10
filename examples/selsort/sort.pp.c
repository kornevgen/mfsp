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
    predicate array_saved{L1, L2}(int *a, integer m, integer n) =
       \forall integer k; m <= k <= n ==> \at(a[k], L1) == \at(a[k], L2);

    predicate count_saved{L1, L2}(int *a, integer m, integer n) =
       \forall integer p; count{L1}(a, m, n, p) == count{L2}(a, m, n, p);

    lemma ordered_frame{L1, L2}: \forall int *a, integer m, n;
        array_saved{L1, L2}(a, m, n)
        ==> (ordered{L1}(a, m, n) <==> ordered{L2}(a, m, n));

    lemma count_frame{L1, L2}: \forall int *a, integer m, n;
        array_saved{L1, L2}(a, m, n - 1)
        ==> count_saved{L1, L2}(a, m, n);*/
// */

/*@
    predicate minimum(int *a, integer m, integer n, integer k) =
        \forall integer i; m <= i < n ==> a[k] <= a[i];*/
// */

/*@
  requires n >= 0;
  requires \valid(a + (0 .. n-1));
  ensures ordered(a, 0, n - 1);
  ensures \forall integer p; count{Here}(a, 0, n, p) == count{Pre}(a, 0, n, p);*/
// */
void sort(int *a, int n);

void sort(int *a, int n)
{
    /*@
        loop invariant i > 0 ==> ordered(a, 0, i - 1);
        loop invariant i > 0 ==> minimum(a, i, n, i - 1);
        loop invariant count_saved{Here, Pre}(a, 0, n);
        loop invariant 0 <= i <= n;
        loop variant n - i;
    */
    for (int i = 0; i < n; ++i) {
        /*@ ghost Liter:*/

        // search for minimum at [i; n)
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
        // move it to a[i]
        if (min_pos != i) {
            /*@ assert \forall integer p;
              count(a, 0, n, p) == count(a, 0, i, p) + count(a, i, n, p) &&
              count(a, i, n, p) == count(a, i, i + 1, p) + count(a, i + 1, n, p) &&
              count(a, i + 1, n, p) == count(a, i + 1, min_pos, p) + count(a, min_pos, n, p) &&
              count(a, min_pos, n, p) == count(a, min_pos, min_pos + 1, p) + count(a, min_pos + 1, n, p);
            */
            int tmp = a[min_pos];
            a[min_pos] = a[i];
            a[i] = tmp;
            /*@ assert array_saved{Here, Liter}(a, 0, i - 1) ==> count_saved{Here, Liter}(a, 0, i);*/
            /*@ assert array_saved{Here, Liter}(a, i + 1, min_pos - 1) ==> count_saved{Here, Liter}(a, i + 1, min_pos);*/
            /*@ assert array_saved{Here, Liter}(a, min_pos + 1, n - 1) ==> count_saved{Here, Liter}(a, min_pos + 1, n);*/
            /*@ assert \forall integer p; count{Here}(a, min_pos, min_pos + 1, p) == count{Liter}(a, i, i + 1, p) && count{Liter}(a, min_pos, min_pos + 1, p) == count{Here}(a, i, i + 1, p);*/

            /*@ assert \forall integer p;
              count(a, 0, n, p) == count(a, 0, i, p) + count(a, i, n, p) &&
              count(a, i, n, p) == count(a, i, i + 1, p) + count(a, i + 1, n, p) &&
              count(a, i + 1, n, p) == count(a, i + 1, min_pos, p) + count(a, min_pos, n, p) &&
              count(a, min_pos, n, p) == count(a, min_pos, min_pos + 1, p) + count(a, min_pos + 1, n, p);
            */
        }
        /*@ assert minimum(a, i, n, i);*/
        /*@ assert minimum(a, i + 1, n, i);*/
        /*@ assert ordered(a, 0, i) <==> ordered(a, 0, i - 1) && ordered(a, i - 1, i);*/
    }
}
