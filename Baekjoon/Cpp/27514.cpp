#include <iostream>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

inline unsigned long long floor(const unsigned long long x)
{
    if (x == 0ULL)
    {
        return 0ULL;
    }

    unsigned long long p = 1ULL;
    while (p <= x / 2ULL)
    {
        p <<= 1ULL;
    }

    return p;
}

int main()
{
    FAST_IO;

    int n;
    cin >> n;

    unsigned long long cache = 0ULL;
    for (int i = 0; i < n; i++)
    {
        unsigned long long x;
        cin >> x;

        cache += x;
    }

    cout << floor(cache);
	
    return 0;
}