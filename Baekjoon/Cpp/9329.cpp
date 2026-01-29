#include <iostream>
#include <cmath>
#include <vector>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> va(n);
        vector<int> vb(n);
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;

            va[i] = vector<int>(k);
            for (int j = 0; j < k; j++)
            {
                cin >> va[i][j];
            }

            cin >> vb[i];
        }

        vector<int> vc(m);
        for (int i = 0; i < m; i++)
        {
            cin >> vc[i];
        }

        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            int mn = 1000001;
            for (int j: va[i])
            {
                mn = min(mn, vc[j - 1]);
            }

            answer += mn * vb[i];
        }

        cout << answer << '\n';
    }

    return 0;
}