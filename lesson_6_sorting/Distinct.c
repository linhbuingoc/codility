// https://codility.com/demo/results/trainingDJPS3V-NPZ/
static int cmp (const void *a, const void *b)
{
    return (*(const int *)a) - (*(const int *)b);
}
int Distinct(int A[], int N)
{
    int last, i, cnt;
    if (N <= 1)
    {
        return N;
    }
    
    qsort(A, N, sizeof(int), cmp);
    for (last = A[0], cnt = 1, i = 1; i < N; i++)
    {
        if (last != A[i])
        {
            last = A[i];
            cnt++;
        }
    }
    
    return cnt;
}