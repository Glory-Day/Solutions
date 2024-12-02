#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

using pii = pair<int, int>;

int n, m;
vector<pii> arr1, arr2;
int answer;

void dfs(vector<int>& caches, int index, int level)
{
    if (level == m)
    {
        int sum = 0;
        for (int i = 0; i < (int)caches.size(); i++)
        {
            sum += caches[i];
        }

        answer = min(answer, sum);

        return;
    }

    vector<int> clone((int)caches.size());
    for (int i = index; i < (int)arr2.size(); i++)
    {    
        for (int j = 0; j < (int)clone.size(); j++)
        {
            clone[j] = min(caches[j], abs(arr1[j].first - arr2[i].first) + abs(arr1[j].second - arr2[i].second));
        }

        dfs(clone, i + 1, level + 1);
    }
}

int main()
{
    cin >> n >> m;

    vector<vector<int>> maps(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maps[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maps[i][j] == 1)
            {
                arr1.push_back({ j,i });
            }
            else if (maps[i][j] == 2)
            {
                arr2.push_back({ j,i });
            }
        }
    }

    vector<int> caches;
    for (int i = 0; i < (int)arr1.size(); i++)
    {
        caches.push_back(INT_MAX);
    }

    answer = INT_MAX;

    dfs(caches, 0, 0);

    cout << answer;
}