#include <iostream>
#include <vector>
#include <algorithm>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    if (v.back() > k)
    {
        cout << -1;

        return 0;
    }

    if (v.front() <= 0)
    {
        cout << 0;

        return 0;
    }

    long long answer = 0;
    for (int i = 1; i < n; i++)
    {
        answer += (k - v[i]) / v[0];
    }
    answer++;

    cout << answer;

    return 0;
}