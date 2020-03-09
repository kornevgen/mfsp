
/*@
    ensures 0 <= \result <= 1;*/
// */
int loop(unsigned N) {
	int c = 0, i;
    /*@
        loop invariant i <= N + 1;
        loop variant N + 1 - i;
    */
	for (i = 1; i <= N; ++i) {
		c = 1 - c;
	}
	return c;
}
