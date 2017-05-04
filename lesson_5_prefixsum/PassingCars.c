// https://codility.com/demo/results/trainingRM5ECE-JU9/
/* Iterate the array, count the number of cars travelling east up to now. Each time 
 * we meet a car travelling west, add the count to the number of passing. */
#define MAX_PASSES 1e9
int PassingCars(int A[], int N) {
    int EastCount = 0;
    int PassesCount = 0;
    int i;
    for (i = 0; i < N; ++i)
    {
        /* a car traveling east */
        if (A[i] == 0)
        {
            EastCount++;
        }
        /* a car traveling west that must pass EastCount car */
        else 
        {
            PassesCount += EastCount;
            if (PassesCount > MAX_PASSES)
            {
                PassesCount = -1;
                break;
            }
        }
    }
    return PassesCount;
}