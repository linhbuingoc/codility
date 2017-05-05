/* https://codility.com/demo/results/trainingBDGWPX-3E3/
 * This problem is similar to counting the number of overlapping intervals.
 * Time Complexity: O(nlog(n)) (due to sorting)
 * Space Complexity: O(n)
 * 
 * 
 *                        =========|
 *              ============|      |
 *   =======================|      |
 *          ===========|    |      |
 *                     |    |      |
 *                     |    |      |
 *                     |    |      |
 *   l                 r                c = 1, cnt = 0
 *          l          r                c = 2, cnt = 1
 *              l      r                c = 3, cnt = 3
 *                        l r           c = 2, cnt = 1
 *                        l r           c = 2, cnt = 3
 * 
 * 
 * 
 */
static int cmp (const void *a, const void *b)
{
    long f = *(const long*)a;
    long s = *(const long*)b;
    if (f > s) return 1;
    if (f < s) return -1;
    return 0;
}
int NumberOfDiscIntersections(int A[], int N) 
{
    long *L, *R; /* Use long to avoid overflow */
    int l, r, cnt, c;
    L = malloc(N*sizeof(long));
    R = malloc(N*sizeof(long));
    
    /* calculate end points */
    for (l = 0; l < N; ++l)
    {
        L[l] = (long)l - A[l];
        R[l] = (long)l + A[l];
    }
    /* sort both array in ascending oder */
    qsort(L, N, sizeof(long), cmp);
    qsort(R, N, sizeof(long), cmp);
    
    /* Current overlapping intervals is 0 */
    c = 0; 
    /* Total overlapping intervals is 0 */
    cnt = 0;
    
    for (l = 0, r = 0; l< N; )
    {
        /* all discs with left end point smaller than or equal to R[r] 
         * overlaps with the disc with right end point R[r] */
        if(L[l] <= R[r])
        {
            /* Increase the number of overlapping discs up to R[r]*/
            c++; 
            /* build up the total number of overlapping discs, exclude itself since L[r] <= R[r]*/
            cnt += c - 1; 
            
            /* Just to satisfy the requirement. Nothing is fancy here.*/
            if (cnt > 1e7)
            {
                cnt = -1;
                break;
            }
            /* next disc */
            l++;
            
        }
        else 
        {
            /* We have done with the disc ending at R[r] so exclude it now */
            c--;
            /* Next disc */
            r++;
        }
    }
    return cnt;
}