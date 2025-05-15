#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
	int caches[11];	
    caches[1] = 1;
    caches[2] = 2;
    caches[3] = 4;
	
	for (int i = 4; i < 11; i++)
	{
        caches[i] = caches[i - 3] + caches[i - 2] + caches[i - 1];
    }
	
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << caches[n] << '\n';
    }
	
	return 0;
}