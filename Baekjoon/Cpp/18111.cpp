#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    int n, m, b;
    cin >> n >> m >> b;

    int matrix[500][500];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int mx = INT_MIN;
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mx = max(mx, matrix[i][j]);
            mn = min(mn, matrix[i][j]);
        }
    }

    int answer[2] = { INT_MAX,0 };
    for (int i = mn; i <= mx; i++)
    {
        int u = 0;
        int v = 0;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                int d = matrix[j][k] - i;
                if (d < 0)
                {
                    u += -d;
                }
                else
                {
                    v += d;
                }
            }
        }

        if (u <= v + b)
        {
            int time = v * 2 + u;
            if (time <= answer[0])
            {
                answer[0] = time;
                answer[1] = i;
            }
        }
    }

    cout << answer[0] << ' ' << answer[1];

    return 0;
}