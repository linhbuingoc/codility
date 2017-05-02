/* Assume that:
 * N is an integer within the range [1..100,000];
 * each element of array A is an integer within the range [
 * −2,147,483,648..2,147,483,647].
 * link: https://codility.com/demo/results/trainingGMK5ZR-5P2/
 */
int MissingInteger(int A[], int N)
{
    int *p = calloc(N + 1, sizeof(int));
    int i;
    for (i = 0; i<N; i++)
    {
        if ((A[i] > 0) && (A[i] <= N))
        {
            p[i]++;
        }
    }
    for (i = 1; i<N+1; i++)
    {
        if(p[i] == 0)
        {
            return i;
        }
    }
    return N + 1;
}