#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int answer = 0;

        if (divisor == INT_MIN)
        {
            return dividend == INT_MIN ? 1 : 0;
        }

        if (dividend == INT_MIN)
        {
            if (divisor == -1)
            {
                return INT_MAX;
            }

            if (divisor == 1)
            {
                return INT_MIN;
            }

            answer++;

            dividend += abs(divisor);
        }

        int a = abs(dividend);
        int b = abs(divisor);
        bool sign = (dividend < 0) ^ (divisor < 0);

        int c = 1;
        while (a > 0)
        {
            if (a >= b)
            {
                a -= b;

                answer += c;

                if (b >> 30)
                {
                    continue;
                }

                b <<= 1;
                c <<= 1;
            }
            else
            {
                if (divisor > a)
                {
                    break;
                }

                b >>= 1;
                c >>= 1;
            }
        }

        return sign ? -answer : answer;
    }
};

int main()
{
    int dividend, divisor;
    cin >> dividend >> divisor;

    int answer = Solution().divide(dividend, divisor);

    cout << answer;

    return 0;
}