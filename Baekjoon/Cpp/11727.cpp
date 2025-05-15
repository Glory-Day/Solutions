#include <iostream>

#define MOD 10007

using namespace std;

int caches[(int)1e3 + 1];

int main()
{
    int n;
    cin >> n;
	
    caches[1] = 1;
    caches[2] = 3;
	
	for (int i = 3; i <= n; i++)
	{
		caches[i] = (caches[i - 1] + 2 * caches[i - 2]) % MOD;
	}
	
    cout << caches[n];
    
	return 0;
}