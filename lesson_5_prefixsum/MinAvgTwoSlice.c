#include <limits.h>

/* The length of min two slice is either 2 or 3.
 * Use prefix sum.
 */

int MinAvgTwoSlice(int A[], int N)
{
    int *P = malloc(sizeof(int)*N);
    int i;
    int s2, s3, index2 = 0, index3 = 0, ms2, ms3;
    
    /* Prefix sum */
    for (P[0] = A[0], i = 1; i < N; P[i] = P[i-1] + A[i], ++i);
    
    /* MinAvg of all slice of length 2 */
    s2 = P[1];
    ms2 = s2;
    for (i = 1; i < N - 1; i++)
    {
        s2 = P[i+1] - P[i-1];
        if (s2 < ms2)
        {
            ms2         = s2;
            index2      = i;
        }
    }
    
    /* MinAvg of all slice of length 3 */
    s3 = P[2];
    ms3 = s3;
    for (i = 2; i < N - 2; i++)
    {
        s3 = P[i+2] - P[i-1];
        if (s3 < ms3)
        {
            ms3         = s3;
            index3      = i;
        }
    }
    
    free(P);
    
    /* select s2 or s3 */
    if (2*ms3 < 3*ms2)
    {
        return index3;
    }
    else if (2*ms3 > 3*ms2)
    {
        return index2;
    }
    else if (index2 < index3)
    {
        return index2;
    }
    return index3;
}