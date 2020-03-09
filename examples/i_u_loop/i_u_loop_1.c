
/*@
    ensures 0 <= \result <= 1;
*/
int loop(unsigned N) {
    int c = 0, i;
    for (i = 1; i <= N; ++i) {
        c = 1 - c;
    }
    return c;
}
