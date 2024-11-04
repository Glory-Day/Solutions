#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

using pii = pair<int, int>;

struct comparator
{
    const bool operator()(const pii& a, const pii& b)
    {
        return a.second < b.second;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pii> maps[1001];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        maps[a].push_back({ b,c });
    }

    int b, e;
    cin >> b >> e;

    priority_queue<pii, vector<pii>, comparator> pq;
    pq.push({ b,0 });

    vector<int> caches(n + 1, INT_MAX);
    caches[b] = 0;

    while (pq.empty() == false)
    {
        auto nd = pq.top();
        pq.pop();

        if (caches[nd.first] < nd.second)
        {
            continue;
        }

        for (const auto& i: maps[nd.first])
        {
            int ncst = i.second + nd.second;
            if (caches[i.first] > ncst)
            {
                caches[i.first] = ncst;

                pq.push({ i.first,ncst });
            }
        }
    }

    cout << caches[e];
}