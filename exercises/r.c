struct Q {
    int *a;
};

void f(int *a1, int *a2)
{
    if (*a1 > *a2) {
        a1 = a2;
    }
}

//@ requires a1 != a2;
void g(int *a1, int *a2)
{
    if (*a1 > *a2) {
        a1 = a2;
    }
}

//@ axiom a1: \forall struct Q *q; \valid(q) ==> \valid(q->a + (0 .. 100));

//@ ensures \result == 0;
int main(void)
{
    struct Q q[10];

    *((q + 1)->a + 2) = 0;
    *((q + 2)->a + 3) = 9;
    return *((q + 3)->a + 4);
}
