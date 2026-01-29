#include <iostream>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int n;
    cin >> n;
	
    int caches[1001];
    caches[1] = 1;
    caches[2] = 3;
	
	for (int i = 3; i <= n; i++)
	{
		caches[i] = (caches[i - 1] + 2 * caches[i - 2]) % 10007;
	}
	
    cout << caches[n];
    
	return 0;
}