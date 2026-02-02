#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(vector<vector<int>> matrix_sizes)
{
    int answer = 0;

    static int cache[200][200];
    fill(&cache[0][0], &cache[0][0] + 200 * 200, -1);

    function<int(int, int)> dfs = [&](int left, int right)
    {
        if (left == right)
        {
            return 0;
        }

        if (cache[left][right] != -1)
        {
            return cache[left][right];
        }

        int result = INT_MAX;
        for (int i = left; i < right; i++)
        {
            int a = dfs(left, i);
            int b = dfs(i + 1, right);
            int c = matrix_sizes[left][0] * matrix_sizes[i][1] * matrix_sizes[right][1];

            result = min(result, a + b + c);
        }

        cache[left][right] = result;

        return result;
    };

    answer = dfs(0, (int)matrix_sizes.size() - 1);

    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix_sizes(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix_sizes[i][j];
        }
    }

    int answer = solution(matrix_sizes);

    cout << answer;

    return 0;
}