#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;

    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        string cache = to_string(i);
        answer += count(cache.begin(), cache.end(), d + '0');
    }

    cout << answer;

    return 0;
}