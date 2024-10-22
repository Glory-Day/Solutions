#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, d;
    cin >> n >> d;

    int caches[10001];
    vector<pii> v[10001];
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({ b,c });
    }

    for (int i = 0; i <= 10000; i++)
    {
        caches[i] = i;
    }

    for (int i = 0; i <= d; i++)
    {
		if (i != 0)
        {
            caches[i] = min(caches[i], caches[i - 1] + 1);
        }

		for(int j = 0; j < (int)v[i].size(); j++)
        {
		    caches[v[i][j].first] = min({ caches[i] + v[i][j].second,caches[i] + (v[i][j].first - i),caches[v[i][j].first] });
		}
	}

    cout << caches[d];

    return 0;
}
