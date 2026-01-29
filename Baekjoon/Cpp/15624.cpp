#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int cache[2] = { 0,1 };
    for (int i = 2; i <= n; i++)
    {
        int sum = (cache[0] + cache[1]) % 1000000007;
        cache[0] = cache[1];
        cache[1] = sum;
    }

    cout << cache[n > 0];

    return 0;
}