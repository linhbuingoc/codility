// https://codility.com/demo/results/training3Z6YSB-V9J/

static int cmp (const void *a, const void *b)
{
    int i1 = *(const int *)a;
    int i2 = *(const int *)b;
    return i1-i2;
}

/* Find maximal product of any triplet.
 * A[i] in [-1,000..1,000]
 * N  in [3..100,000] */
int MaxProductOfThree (int A[], int N)
{
    int p1, p2;
    qsort(A, N, sizeof(int), cmp);
    p1 = A[0] * A[1] * A[N-1];  /* Two smallest negatives and the largest */ 
    p2 = A[N-3] * A[N-2] * A[N-1];
    return (p1<p2)?p2:p1;
}