/*
 * 1 <= X <= Y <= 1e9
 */
int FrogJmp(int X, int Y, int D)
{
    int t = Y - X;
    return t/D + ((t%D) > 0);
}