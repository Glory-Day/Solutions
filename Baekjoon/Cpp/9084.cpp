#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int m;
        cin >> m;

        vector<int> caches(m + 1, 0);
        caches[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (v[i] <= j)
                {
                    caches[j] += caches[j - v[i]];
                }
            }
        }

        cout << caches[m] << '\n';
    }
}