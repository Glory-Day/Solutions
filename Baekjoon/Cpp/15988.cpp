#include <iostream>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int t;
    cin >> t;
    
	unsigned int caches[1000001];
    caches[1] = 1;
    caches[2] = 2;
    caches[3] = 4;
	
	for (int i = 4; i < 1000001; i++)
	{
        caches[i] = (caches[i - 3] + caches[i - 2] + caches[i - 1]) % 1000000009U;
    }
	
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << caches[n] << '\n';
    }
	
	return 0;
}