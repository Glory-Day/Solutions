#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

#define AND &

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int cache = v[0];
    for (int i = 1; i < n; i++)
    {
        cache = lcm(cache, v[i]);
    }

    int answer = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        double sum = 0.0;
        for (int j = 0; j < n; j++)
        {
            if (i AND (1 << j))
            {
                sum += cache / v[j];
            }
        }
        sum /= cache;

        if (0.99 <= sum && sum <= 1.01)
        {
            answer++;
        }
    }

    cout << answer;

    return 0;
}