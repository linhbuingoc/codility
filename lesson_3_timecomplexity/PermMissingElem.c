
/*
 * N = 0, output is 1
 * 1 + 2 + .... + N + (N + 1) = (N + 1)*(N + 2)/2
 */
int PermMissingElement(int A[], int N) {
    int i = 0;
    long total = 0;
    long sum = 0;

    for (i = 0; i < N; i++)
    {
        sum += (long)A[i];
    }
    
    total = ((long)N+1) * ((long)N+2);
    total >>= 1;
    return total - sum;
}