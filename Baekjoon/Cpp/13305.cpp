#include <iostream>
#include <cmath>
#include <climits>
#include <vector>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int n;
    cin >> n;

    vector<long long> v(n - 1);
    vector<long long> w(n);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    long long answer = 0LL;
    long long cache = LLONG_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        cache = min(cache, w[i]);
        answer += (cache * v[i]);
    }

    cout << answer;

    return 0;
}