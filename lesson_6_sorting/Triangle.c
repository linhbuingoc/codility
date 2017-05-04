// https://codility.com/demo/results/trainingXRZDV8-PT5/
static int cmp (const void *a, const void *b)
{
    int f = *(const int*)a;
    int s = *(const int*)b;
    if (f < s) return -1;
    if (f == s) return 0;
    return 1;
}

int solution(int A[], int N) {
    int i;
    if (N < 3) return 0;
    qsort(A, N, sizeof(int), cmp);
    for (i = 0; i <= N-3; ++i)
    {
        if ((A[i] > 0) && /* just make the branch faster */
            (((long)A[i] + (long)A[i+1]) > (long)A[i+2]))
        {
            return 1;
        }
    }
    return 0;
}