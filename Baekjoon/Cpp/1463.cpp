#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
	
	int caches[(int)1e6 + 1];
    caches[2] = 1;
    caches[3] = 1;
	
    for (int i = 4; i <= n; i++)
    {
        int a = (i % 3 == 0) ? caches[i / 3] : INT_MAX;
        int b = (i % 2 == 0) ? caches[i / 2] : INT_MAX;
        int c = caches[i - 1];
		
        caches[i] = min(a, min(b, c)) + 1;
    }
	
    cout << caches[n];
	
	return 0;
}