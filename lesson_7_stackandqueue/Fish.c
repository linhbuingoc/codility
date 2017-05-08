// https://codility.com/demo/results/trainingU9C82A-KV4/
int Fish(int A[], int B[], int N)
{
    int *OneAlive       = malloc(N*sizeof(int))
    int OneCnt      = 0;
    int ZeroCnt     = 0;
    int i;
    
    /* For each fish */
    for (i =0; i<N; ++i)
    {
        /* This is a downstream fish */
        if (B[i] == 1)
        {
            /* Add it to stack */
            OneAlive[OneCnt++] = A[i];
        }
        /* This is an upstream fish and it must meet alive downstream 
         * fishes one by one */
        else
        {
            /* Let this upstream fish eats up as many downstream fishes 
             * as possible, or is eaten up. */
            while ((OneCnt > 0) &&  /* Not empty */
                   (OneAlive[OneCnt - 1] < A[i])) /* downstream fish is bigger */
            {
                OneCnt--;
            }
            /* The upstream fish is alive if all downstream fishes are eaten, which
             is an empty stack. */
            ZeroCnt += OneCnt == 0;
        }
    }
    free(OneAlive);
    return ZeroCnt + OneCnt;
}