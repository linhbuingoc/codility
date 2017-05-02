/*
 * N in [2..1e5]
 * A[i] in [-1e3..1e3]
 * Time O(N)
 * Space O(N)
 */
 #include <limits.h>
int TapeEquilibrium(int A[], int N)
{
    int *p = malloc(sizeof(int) * N);
    int i, min_sum = INT_MAX, right_sum, left_sum, tmp;
    
    for (p[0] = A[0], i = 1; i < N; i++)
    {
        p[i] = p[i-1] + A[i];
    }
    
    for (i = 1; i<N; i++)
    {
        left_sum = p[i-1];
        right_sum = p[N-1] - left_sum;
        tmp = abs(left_sum-right_sum);
        if (tmp < min_sum)
        {
            min_sum = tmp;
            if (min_sum == 0)
            {
                break;
            }
        }
    }
    
    return min_sum;
}
