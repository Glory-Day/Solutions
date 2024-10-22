#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

#define MAX 300000

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v;
    for (int i = 1; v.empty() || v.back() <= MAX; i++)
    {
        v.push_back(i * (i + 1) * (i + 2) / 6);
    }
    v.pop_back();

    vector<ll> caches(MAX + 1, INT_MAX);
	for (int i = 0;i < (int)v.size(); i++) 
    {
        caches[v[i]] = 1;
    }
	
	for (int i = 0; i < (int)v.size(); i++) 
    {
		for (int j = v[i]; j <= n; j++)
        {
			caches[j] = min(caches[j],caches[j - v[i]] + 1);
		}
	}

	cout << caches[n];
}