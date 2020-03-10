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
        loop invariant 0 <= i <= n;
        loop variant n - i;
    */
    for (int i = 0; i < n; ++i) {
        int min_pos = i;
        /*@
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
            int tmp = a[min_pos];
            a[min_pos] = a[i];
            a[i] = tmp;
        }
    }
}
