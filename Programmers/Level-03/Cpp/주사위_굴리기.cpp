#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(vector<vector<int>> dice)
{
    vector<int> answer;
    
    int size = (int)dice.size();
    vector<vector<int>> combinations;
    vector<int> visited;

    function<void(int)> get_combinations = [&](int start)
    {
        if ((int)visited.size() == size / 2)
        {
            combinations.push_back(visited);

            return;
        }

        for (int i = start; i < size; i++)
        {
            visited.push_back(i);
            get_combinations(i + 1);
            visited.pop_back();
        }
    };

    get_combinations(0);

    int cache = 0;
    for (int i = 0; i < (int)combinations.size() / 2; i++)
    {
        vector<int> dices[2];
        vector<int> sums[2];

        function<void(int, int, int)> get_sums = [&](int index, int sum, int depth)
        {
            if (depth == (int)dices[index].size())
            {
                sums[index].push_back(sum);
                return;
            }

            int i = dices[index][depth];
            for (int j = 0; j < 6; j++)
            {
                get_sums(index, sum + dice[i][j], depth + 1);
            }
        };

        vector<int> used(size, 0);

        for (int combination : combinations[i])
        {
            dices[0].push_back(combination);

            used[combination] = 1;
        }

        for (int j = 0; j < size; j++)
        {
            if (used[j] == false)
            {
                dices[1].push_back(j);
            }
        }

        get_sums(0, 0, 0);
        get_sums(1, 0, 0);

        long long caches[2] = { 0,0 };

        sort(sums[1].begin(), sums[1].end());
        for (int j : sums[0])
        {
            caches[0] += lower_bound(sums[1].begin(), sums[1].end(), j) - sums[1].begin();
        }

        sort(sums[0].begin(), sums[0].end());
        for (int j : sums[1])
        {
            caches[1] += lower_bound(sums[0].begin(), sums[0].end(), j) - sums[0].begin();
        }

        if (caches[0] > cache)
        {
            cache = (int)caches[0];
            answer = dices[0];
        }

        if (caches[1] > cache)
        {
            cache = (int)caches[1];
            answer = dices[1];
        }
    }

    for (int& index : answer)
    {
        index++;
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> dices(n, vector<int>(6));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> dices[i][j];
        }
    }

    vector<int> answer = solution(dices);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}