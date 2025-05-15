#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;

    ll b = 1, e = n * n, answer = 0;
    while (b <= e)
    {
        ll mid = (b + e) / 2;
        ll cnt = 0;
		
        for (int i = 1; i <= n; i++)
        {
            cnt += min((ll)n, mid / (ll)i);
        }
		
        if (cnt >= k)
        {
            answer = mid;
            e = mid - 1;
        }
        else
        {
            b = mid + 1;
        }
    }
	
    cout << answer;
	
	return 0;
}