/* A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is
 * surrounded by ones at both ends in the binary representation of N.
 * For example, number 9 has binary representation 1001 and contains a binary gap of length 2.
 * The number 529 has binary representation 1000010001 and contains two binary gaps: one of length
 * 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap
 * of length 1. The number 15 has binary representation 1111 and has no binary gaps.
 * Assume that:
 *      N is an integer within the range [1..2,147,483,647].
 * Complexity:
 *      expected worst-case time complexity is O(log(N));
 *      expected worst-case space complexity is O(1).
 */


int BinaryGap (int N)
{
    int cnt = 0, ret = 0;
    int flg = 0;
    while (N)
    {
        if(N&1)
        {
            flg++;
            if ((cnt > ret) && (flg > 1))
            {
                ret = cnt;
            }
            cnt = 0;
        }
        else
        {
            cnt += flg > 0;
        }

        N >>= 1;
    }
    return ret;
}
