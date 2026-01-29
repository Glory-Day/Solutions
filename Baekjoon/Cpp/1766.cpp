#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<int> e(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        
        g[a].push_back(b);
        e[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (e[i] == 0)
        {
            pq.push(i);
        }
    }

    vector<int> answer;
    answer.reserve(n);

    while (pq.empty() == false)
    {
        int nd = pq.top();
        pq.pop();

        answer.push_back(nd);

        for (const int& i: g[nd])
        {
            if (--e[i] == 0)
            {
                pq.push(i);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}