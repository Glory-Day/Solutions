#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int n, m;
    cin >> n >> m;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        pq.push(x);
    }

    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    long long sum = 0LL;
    for (int i = 0; i < m; i++)
    {
        int a = v[i].first;
        int b = v[i].second;

        while (sum < b)
        {
            if (pq.empty())
            {
                cout << -1;

                return 0;
            }

            sum += pq.top() + a;
            pq.pop();
        }
    }

    int cache = v.back().first;
    while (pq.empty() == false)
    {
        sum += pq.top() + cache;
        pq.pop();
    }
    
    cout << (sum < v.back().second ? -1 : sum);

    return 0;
}