/* https://codility.com/demo/results/trainingDKZFCJ-ME2/ */
int PermCheck(int A[], int N)
{
    int *map = calloc(N + 1, sizeof(int));
    int i = 0;
    int ret = 1;
    for (i = 0; i<N; i++)
    {
        if (A[i] > N)
        {
            ret = 0;
            break;
        }
        else if (map[A[i]] > 0)
        {
            ret = 0;
            break;
        }
        else
        {
            map[A[i]]++;
        }
    }
    free(map);
    return ret;
}