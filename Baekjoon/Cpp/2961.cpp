#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <utility>

#define AND &

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    int answer = INT_MAX;
    for (int i = 1; i < (1 << n); i++)
    {
        int a = 1;
        int b = 0;
        for (int j = 0; j < n; j++)
        {
            if (i AND (1 << j))
            {
                a *= v[j].first;
                b += v[j].second;
            }
        }

        answer = min(answer, abs(a - b));
    }

    cout << answer;

    return 0;
}