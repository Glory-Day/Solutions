#include <iostream>

using namespace std;

using ll = long long;

ll caches[55];

ll f(ll x)
{
    ll y = x & 1, a = 0;
    for (int i = 54; i > 0; i--)
    {
        a = (1LL << i);
        if (x & a)
        {
            y += caches[i - 1] + (x - a + 1);
            x -= a;
        }
    }
	
    return y;
}

int main()
{
    ll a, b;
    cin >> a >> b;
	
    caches[0] = 1;
    for (int i = 1; i < 55; i++)
    {
        caches[i] = caches[i - 1] * 2 + (1LL << i);
    }
	
    cout << f(b) - f(a - 1);
	
	return 0;
}