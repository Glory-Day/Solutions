#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;

    static int cache[100];
    fill(&cache[0], &cache[0] + 100, 0);

    for (int i = 0; i < n; i++)
    {
        cache[i] = i;
    }

    auto compare = [&](const vector<int>& lhs, const vector<int>& rhs)
    {
        return lhs[2] < rhs[2];
    };

    sort(costs.begin(), costs.end(), compare);

    function<int(int)> find = [&](int x)
    {
        return cache[x] == x ? x : cache[x] = find(cache[x]);
    };

    auto unite = [&](int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a != b)
        {
            cache[a] = b;
        }
    };

    int count = 0;
    for (const auto& cost: costs)
    {
        int a = cost[0];
        int b = cost[1];
        int c = cost[2];

        if (find(a) != find(b))
        {
            unite(a, b);

            answer += c;
            count++;
        }

        if (count == n - 1)
        {
            break;
        }
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;

    int m, k;
    cin >> m >> k;

    vector<vector<int>> costs(m, vector<int>(k));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> costs[i][j];
        }
    }

    int answer = solution(n, costs);

    cout << answer << '\n';

    return 0;
}