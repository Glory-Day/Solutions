#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    n += 2;

    vector<int> cache(n + 1, 0);
    cache[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = i / 2; j > 0; j--)
        {
            cache[i - j] = cache[j] = (cache[j - 1] + cache[j]) % 10007;
        }
    }

    cout << cache[k + 1];

    return 0;
}