// https://codility.com/demo/results/training4K8WCW-EBB/
int FrogRiverOne(int X, int A[], int N) 
{
    int *map = calloc(1+X, sizeof(int));
    int i, step;
    for (step = 0, i = 0; i<N; i++)
    {
        if (map[A[i]] == 0)
        {
            /* Mark this one as available */
            map[A[i]] = 1;
            step++;
            /* The whole road is available now */
            if (step == X)
            {
                return i;
            }
        }
    }
    return -1;
}