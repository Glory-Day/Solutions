#include <iostream>

#define P 1000000000;

using namespace std;

int caches[101][10][1 << 10];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i < 10; i++)
    {
        caches[1][i][1 << i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < (1 << 10); k++)
            {
                int bit = k | (1 << j);
                switch (j)
                {
                case 0:
                    caches[i][j][bit] += caches[i - 1][j + 1][k];
                    break;
                case 9:
                    caches[i][j][bit] += caches[i - 1][j - 1][k];
                    break;
                default:
                    caches[i][j][bit] += caches[i - 1][j - 1][k];
                    caches[i][j][bit] += caches[i - 1][j + 1][k];
                    break;
                }

                caches[i][j][bit] %= P;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < 10; i++)
    {
        answer += caches[n][i][(1 << 10) - 1];
        answer %= P;
    }

    cout << answer;

    return 0;
}