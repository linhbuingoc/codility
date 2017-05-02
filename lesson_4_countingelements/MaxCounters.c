// https://codility.com/demo/results/trainingA6NR96-6G8/#task-0
struct Results {
  int * C;
  int L;
};
struct Results MaxCounters(int N, int A[], int M) 
{
    struct Results result;
    int i, j, max = 0;
    result.C = calloc(N, sizeof(int));
    result.L = N;
    
    for (i = 0; i<M; i++)
    {
        if (A[i] <= N)
        {
            if (result.C[A[i] - 1] < floor)
            {
                result.C[A[i] - 1] = floor;
            }
            result.C[A[i] - 1]++;
            if (result.C[A[i] - 1] > max)
            {
                max = result.C[A[i] - 1];
            }
        }
        else 
        {
            floor = max;
        }
    }
    
    for (i = 0; i<M; i++)
    {
        if (result.C[i] < floor)
        {
            result.C[i] = floor;
        }
    }
    return result;
}
