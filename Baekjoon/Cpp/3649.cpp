#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x;
    while (cin >> x)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        x *= 10000000;

        sort(v.begin(), v.end());

        int b = 0;
        int e = (int)v.size() - 1;
        int sum = 0;
        while (b < e)
        {
            sum = v[b] + v[e];
            if (sum < x)
            {
                b++;
            }
            else if (sum > x)
            {
                e--;
            }
            else
            {
                break;
            }
        }

        if (sum == x)
        {
            cout << "yes " << v[b] << ' ' << v[e] << '\n';
        }
        else
        {
            cout << "danger" << '\n';
        }
    }
}