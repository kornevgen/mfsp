int search(int *a, int n, int x)
{
    int i = 0;
    int zero = 0;
    while (1) {
        if (a[i] == 0) {
            if (zero) {
                return -1;
            }
            zero = 1;
        } else {
            if (a[i] == x) {
                return i;
            }
            zero = 0;
        }
        ++i;
    }
}
