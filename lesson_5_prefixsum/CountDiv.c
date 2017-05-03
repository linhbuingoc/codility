int CountDiv (int A, int B, int K)
{
    return B/K - A/K + ((A%K) == 0);
}