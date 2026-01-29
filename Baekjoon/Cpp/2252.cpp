#include <iostream>
#include <vector>
#include <functional>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<int> e(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[b].push_back(a);
        e[a] = 1;
    }

    function<void(int)> dfs = [&](const int nd)
    {
        for (const int& i: g[nd])
        {
            if (e[i] != -1)
            {
                dfs(i);
            }
        }

        e[nd] = -1;

        cout << nd << ' ';
    };

    for (int i = 1; i <= n; i++)
    {
        if (e[i] == 0)
        {
            dfs(i);
        }
    }

    return 0;
}