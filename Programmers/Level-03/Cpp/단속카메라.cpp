#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 0;

    auto compare = [&](const vector<int>& lhs, const vector<int>& rhs)
    {
        return lhs[1] < rhs[1];
    };

    sort(routes.begin(), routes.end(), compare);

    int cache = INT_MIN;
    for (const auto& route: routes)
    {
        if (cache < route[0])
        {
            cache = route[1];

            answer++;
        }
    }

    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> routes(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> routes[i][j];
        }
    }

    int answer = solution(routes);

    cout << answer << '\n';

    return 0;
}