#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll caches[101][21];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
    int n;
    cin >> n;
	
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
	
    caches[1][v[1]] = 1;
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (caches[i - 1][j])
            {
                if (j + v[i] <= 20)
                {
                    caches[i][j + v[i]] += caches[i - 1][j];
                }
				
                if (j - v[i] >= 0)
                {
                    caches[i][j - v[i]] += caches[i - 1][j];
                }
            }
        }
    }
	
    ll answer = caches[n - 1][v[n]];
	
    cout << answer << '\n';
	
    return 0;
}