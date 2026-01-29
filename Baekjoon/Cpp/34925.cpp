#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long h, s;
    cin >> h >> s;

    long long answer;
    if (h <= 2)
    {
        answer = 1;
    }
    else if (2 < h && h <= 4)
    {
        answer = s + 2;
    }
    else
    {
        answer = ((h + 1) / 2) + 3 * (s / 2) + (s % 2) * (h % 2 == 0 ? 2 : 1);
    }

    cout << answer;

    return 0;
}