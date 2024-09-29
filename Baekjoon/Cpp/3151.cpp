#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    ll answer = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = v[i] + v[j];
            auto b = v.begin() + j + 1;
            auto e = v.end();
            answer += upper_bound(b, e, -sum) - lower_bound(b, e, -sum);
        }
    }

    cout << answer;

    return 0;
}