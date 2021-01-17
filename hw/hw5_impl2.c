#include "hw5.h"

int defragment(int *a, int n, int *from, int *to)
{
    int i = 0;
    int f = -1;
    int zero = 0;
    while (1) {
        if (a[i] == 0) {
            if (f == -1) { // it is the first zero
                f = i;
            } else if (zero) { // two zeros
                if (f == i - 1) { // array doesn't have a hole
                    return 0;
                }
                i -= 2;
                *to = f;
                *from = i;
                int r = (a[f] = a[i]);
                a[i] = 0;
                return r;
            }
            zero = 1;
        } else {
            zero = 0;
        }
        ++ i;
    }
}
