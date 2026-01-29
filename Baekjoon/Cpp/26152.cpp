#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second;
    }

    int m;
    cin >> m;

    vector<int> w(m);
    for (int i = 0; i < m; i++)
    {
        cin >> w[i];
    }

    vector<int> caches(n);
    for (int i = 0; i < n; i++)
    {
        int d = v[i].first - v[i].second;
        caches[i] = (i == 0) ? d : min(caches[i - 1], d);
    }

    vector<int> answer(m);
    for (int i = 0; i < m; i++)
    {
        answer[i] = upper_bound(caches.begin(), caches.end(), w[i], greater<int>()) - caches.begin();
    }

    for (int i = 0; i < m; i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}