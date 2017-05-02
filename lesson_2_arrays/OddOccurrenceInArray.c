/* Find the element that occurs odd number of times. 
 * All other elements occur even number of times.
 * Use the magical XOR operator.
 * a ^ 0 = a
 * a ^ a = 0
 */
int OddOccurrencesInArray(int A[], int N)
{
    int i;
    int odd = A[0];
    for (i = 1; i<N; i++) 
    {
        odd ^= A[i];
    }
    return odd;
}