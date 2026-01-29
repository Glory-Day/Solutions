#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>

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

    auto f = [&]()
    {
        long long sum = 0LL;
        long long cache = 0LL;

        int length = min(n, k);
        for (int i = 0; i < length; i++)
        {
            cache = max(cache, sum + (long long)(k - i) * (long long)v[i]);
            sum += (long long)v[i];
        }

        return cache;
    };

    long long answer = max(0LL, f());

    reverse(v.begin(), v.end());

    answer = max(answer, f());

    cout << answer;

    return 0;
}