// https://codility.com/demo/results/trainingRBUE9U-DCR/
 
#define MAX_NUC 4
const char nucleotides[MAX_NUC] = {'A', 'C', 'G', 'T'};
 
struct Results solution(char *S, int P[], int Q[], int M) {
    struct Results result;
    int *last_index[4];
    int i, j, l = strlen(S);

    result.A = malloc(M*sizeof(int));
    result.M = M;
    
    for (i = 0; i<MAX_NUC; i++)
    {
        last_index[i] = malloc(l*sizeof(int));
    }
    
    /* Find occurence position of first nucleotide in S*/
    for (j = 0; j < MAX_NUC; j++)
    {
        /* -1: Not yet occurred in S */
        last_index[j][0] = -1 + (S[0] == nucleotides[j]);
    }
    /* Find occurence position of ith nucleotide in S*/
    for (i = 1; i<l; i++)
    {
        for (j = 0; j < MAX_NUC; j++)
        {
            /* If j th nucleotide is S[i], the occurence of this nucleotide in S is i th.
             * Otherwise, the occurence of the j th nucleotide in S is the same with the last occurence.
             */
            last_index[j][i] = (S[i] == nucleotides[j])? i : last_index[j][i-1];
        }
    }
    
    for (i = 0; i<M; i++)
    {
        result.A[i] = -1;
        for (j = 0; j < MAX_NUC; j++)
        {
            /* within the range from P[i] to Q[i], is there at least one j th nucleotide? */
            if ((last_index[j][Q[i]] >= P[i]) && 
                (last_index[j][P[i]] <= Q[i]))
            {
                /* YES */
                result.A[i] = j + 1;
                break;
            }
        }
        
    }
    
    return result;
}