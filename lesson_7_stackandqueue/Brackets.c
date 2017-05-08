// https://codility.com/demo/results/trainingZT63NF-U8S/
int Brackets(char *S)
{
    int     i;
    char    *stk;
    int     top;
    int     l       = strlen(S);

    if (l&1)
    {
        return 0;
    }
    
    if (l == 0)
    {
        return 1;
    }
    
    /* Allocate stack */
    stk         = malloc(l);
    top         = 0;

    for (i =0; i<l; ++i)
    {
        if ((S[i] == '[') ||(S[i] == '(') ||(S[i] == '{'))
        {
            stk[top++] = S[i];
        }
        else
        {
            /* Empty stack */
            if (top == 0)
            {
                /* Make the stack appear to be not empty so the function return false */
                top = 1;
                break;
            }
            
            /* Does o=top stack matches with S[i] */
            --top;
            if (!(((stk[top] == '[') && (S[i] == ']')) ||
                  ((stk[top] == '{') && (S[i] == '}')) ||
                  ((stk[top] == '(') && (S[i] == ')'))))
            {
                /* Make the stack appear to be not empty so the function return false */
                top = 1;
                break;
            }
        }
    } 

    free(stk);
    return (top == 0);
}