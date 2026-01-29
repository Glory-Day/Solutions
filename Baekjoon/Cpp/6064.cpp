#include <iostream>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

inline int gcd(const int lhs, const int rhs)
{
    return rhs == 0 ? lhs : gcd(rhs, lhs % rhs);
}

inline int lcm(const int lhs, const int rhs)
{
    return (lhs * rhs) / gcd(lhs, rhs);
}

int main()
{
    FAST_IO;

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        int cache = lcm(n, m);
        while (x <= cache)
        {
            if ((x - 1) % m + 1 == y || x > cache)
            {
                break;
            }

            x += n;
        }

        int answer = (x > cache ? -1 : x);

        cout << answer << '\n';
    }

    return 0;
}