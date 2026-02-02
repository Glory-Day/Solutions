#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<vector<int>> scores)
{
    int answer = 0;

    int a = scores[0][0];
    int b = scores[0][1];
    int sum = a + b;

    auto compare = [&](const vector<int>& lhs, const vector<int>& rhs)
    {
        return lhs[0] != rhs[0] ? lhs[0] > rhs[0] : lhs[1] < rhs[1];
    };

    sort(scores.begin(), scores.end(), compare);

    int cache = 0;
    int count = 1;
    for (const auto& score: scores)
    {
        int na = score[0];
        int nb = score[1];

        if (nb < cache)
        {
            if (na == a && nb == b)
            {
                return -1;
            }

            continue;
        }

        cache = max(cache, nb);

        if (na + nb > sum)
        {
            count++;
        }
    }

    answer = count;

    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> scores(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i][0] >> scores[i][1];
    }

    int answer = solution(scores);

    cout << answer << '\n';

    return 0;
}