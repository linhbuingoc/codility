/* Rotate an array of N elements K steps */

struct Results {
    int *A;
    int N;
};
struct Results solution(int A[], int N, int K) {
    struct Results result;
    int i, j;
    result.N = N;
    
    if (N == 0) return result;
    
    K %= N;
    result.A = malloc(N*sizeof(int));
    
    for (i = 0, j = K; i<N; i++)
    {
        result.A[j] = A[i];
        j = (j+1)%N;
    }
    
    return result;
}