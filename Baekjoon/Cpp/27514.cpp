#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
	
    int caches[64] = { 0, };
    for (int i = 0; i < n ; i++)
    {
        long long a;
        cin >> a;
		
        if (a > 0)
        {
            caches[(int)log2l((long double)a)]++;
        }
    }
	
    int index = 0;
    for (int i = 0; i < 63; i++)
    {
        caches[i + 1] += caches[i] / 2;
		
        if (caches[i + 1] > 0)
        {
            index = i + 1;
        }
    }
	
    cout << (1LL << index);
	
    return 0;
}