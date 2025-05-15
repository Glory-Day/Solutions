#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
	
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
		
        double d = y - x;
        double p = sqrt(d);
        int r = round(sqrt(d));
		
        if (p <= r)
        {
            cout << r * 2 - 1 << '\n';
        }
        else
        {
            cout << r * 2 << '\n';
        }
    }
	
	return 0;
}