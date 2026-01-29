#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(200, 0);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;

            if (a > b)
            {
                swap(a, b);
            }

            a = (a - 1) / 2;
            b = (b - 1) / 2;

            v[a]++;
            v[b + 1]--;
        }

        int cache = 0;
        int answer = 0;
        for (int i = 0; i < 200; i++)
        {
            cache += v[i];
            answer = max(answer, cache);
        }

        answer *= 10;

        cout << answer << '\n';
    }

    return 0;
}