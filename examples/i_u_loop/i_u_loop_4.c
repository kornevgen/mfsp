
/*@
    ensures 0 <= \result <= 1;
*/
int loop(unsigned N) {
    int c = 0;
    unsigned i;
    /*@
        loop invariant 0 <= c <= 1;
        loop invariant i <= N;
        loop variant N - i;
    */
    for (i = 0; i < N; ++i) {
        c = 1 - c;
    }
    return c;
}
