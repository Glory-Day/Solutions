#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int>& arr, vector<int>& caches, vector<vector<int>>& output, int level, int limit)
{
    if (limit == level)
    {
        vector<int> line;
        for (int i = 0; i < (int)caches.size(); i++)
        {
            line.push_back(arr[caches[i]]);
        }

        output.push_back(line);

        return;
    }

    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (find(caches.begin(), caches.end(), i) != caches.end())
        {
            continue;
        }

        caches.push_back(i);

        dfs(arr, caches, output, level + 1, limit);

        caches.pop_back();
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> caches;
    vector<vector<int>> answer;

    dfs(arr, caches, answer, 0, m);

    sort(answer.begin(), answer.end(), [](const vector<int>& a, const vector<int>& b) {
        bool flag = false;
        for (int i = 0; i < (int)a.size(); i++)
        {
            if (a[i] != b[i])
            {
                flag = a[i] < b[i];

                break;
            }
        }

        return flag;
    });


    for (int i = 0; i < (int)answer.size(); i++)
    {
        for (int j = 0; j < (int)answer[i].size(); j++)
        {
            cout << answer[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}