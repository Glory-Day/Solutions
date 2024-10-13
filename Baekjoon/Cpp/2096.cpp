#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int caches[2][3] = { 0, };
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int u = max(caches[0][0], caches[0][1]);
        int v = max(caches[0][1], caches[0][2]);

        caches[0][0] = a + u;
        caches[0][1] = b + max(u, v);
        caches[0][2] = c + v;

        u = min(caches[1][0], caches[1][1]);
        v = min(caches[1][1], caches[1][2]);

        caches[1][0] = a + u;
        caches[1][1] = b + min(u, v);
        caches[1][2] = c + v;
    }

    int answer[2];
    answer[0] = max(caches[0][0], max(caches[0][1], caches[0][2]));
    answer[1] = min(caches[1][0], min(caches[1][1], caches[1][2]));

    cout << answer[0] << ' ' << answer[1];

    return 0;
}