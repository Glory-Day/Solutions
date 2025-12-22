#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int cache[3] = { 0, };
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        int a = s[0] - '0';
        int b = s[2] - '0';
        cache[(a + b - 3) / 2]++;
    }

    n = min(cache[1], cache[2]);
    cache[1] -= n;
    cache[2] -= n;

    cache[0] += cache[1] / 2;
    cache[1] %= 2;
    
    n += cache[0] / 2;
    cache[0] %= 2;

    int answer = n + (0 < cache[0] + cache[1]) + cache[2];

    cout << answer;

    return 0;
}