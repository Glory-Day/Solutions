#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int node[2];
    int cost;

    edge(int a, int b, int cost) : node{ a,b }, cost(cost) {}

    const bool operator<(const edge &other)
    {
        return this->cost < other.cost;
    }
};

int caches[1001];

const int find(const int i)
{
    if (caches[i] == i)
    {
        return i;
    }

    return caches[i] = find(caches[i]);
}

const bool isCycle(const int a, const int b)
{
    return find(a) == find(b);
}

void merge(const int a, const int b)
{
    caches[find(b)] = find(a);
}

int main()
{
    for (int i = 1; i <= 1000; i++)
    {
        caches[i] = i;
    }

    int n, m;
    cin >> n >> m;

    vector<edge> v;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v.push_back({ a,b,c });
    }

    sort(v.begin(), v.end());

    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        if (isCycle(v[i].node[0], v[i].node[1]) == false)
        {
            merge(v[i].node[0], v[i].node[1]);

            answer += v[i].cost;
        }
    }

    cout << answer;

    return 0;
}