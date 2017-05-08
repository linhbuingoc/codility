// https://codility.com/demo/results/trainingD95APS-A2D/
int Nesting(char *S)
{
    int     top;
    for (top = 0; *S != '\0' ; S++)
    {
        if (*S == '(')
        {
            ++top;
        }
        else
        {
            /* Empty stack */
            if (top == 0)
            {
                /* Make the stack appears to be not empty so the function returns false */
                top = 1;
                break;
            }
            --top;
        }
    } 

    return (top == 0);
}