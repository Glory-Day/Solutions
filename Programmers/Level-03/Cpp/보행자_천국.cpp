#include <iostream>
#include <vector>

using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map)
{
    int answer = 0;

    vector<vector<int>> a(m, vector<int>(n, 0));
    vector<vector<int>> b(m, vector<int>(n, 0));

    if (city_map[0][0] == 1)
    {
        return 0;
    }

    a[0][0] = 1;
    b[0][0] = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            if (city_map[i][j] == 1)
            {
                a[i][j] = 0;
                b[i][j] = 0;
                continue;
            }

            if (j > 0 && city_map[i][j - 1] != 1)
            {
                if (city_map[i][j - 1] == 2)
                {
                    a[i][j] = a[i][j - 1];
                }
                else
                {
                    a[i][j] = a[i][j - 1] + b[i][j - 1];
                    a[i][j] %= MOD;
                }
            }

            if (i > 0 && city_map[i - 1][j] != 1)
            {
                if (city_map[i - 1][j] == 2)
                {
                    b[i][j] = b[i - 1][j];
                }
                else
                {
                    b[i][j] = a[i - 1][j] + b[i - 1][j];
                    b[i][j] %= MOD;
                }
            }
        }
    }

    answer = (a[m - 1][n - 1] + b[m - 1][n - 1]) % MOD;

    return answer;
}

int main()
{
    int n, m;
    cin >> m  >> n;

    vector<vector<int>> city_map(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> city_map[i][j];
        }
    }

    int answer = solution(m, n, city_map);

    cout << answer << '\n';

    return 0;
}