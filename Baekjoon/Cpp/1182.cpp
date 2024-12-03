#include <iostream>
#include <vector>

using namespace std;

int n, s;
vector<int> arr;

int limit;

int dfs(vector<int>& caches, int index, int level)
{
    int answer = 0;

    if (level == limit)
    {
        int sum = 0;
        for (int i = 0; i < (int)caches.size(); i++)
        {
            sum += caches[i];
        }

        return (sum == s ? 1 : 0);
    }

    for (int i = index; i < (int)arr.size(); i++)
    {
        caches.push_back(arr[i]);

        answer += dfs(caches, i + 1, level + 1);

        caches.pop_back();
    }

    return answer;
}

int main()
{
    cin >> n >> s;

    arr = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int answer = 0;
    vector<int> caches;
    for (int i = 1; i <= n; i++)
    {
        limit = i;

        answer += dfs(caches, 0, 0);
    }

    cout << answer;
}