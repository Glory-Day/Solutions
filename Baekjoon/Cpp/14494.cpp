#include <iostream>
#include <vector>
#include <cmath>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define MOD 1000000007LL

using namespace std;

int main()
{
    FAST_IO;
	
    int n, m;
    cin >> n >> m;
	
    vector<int> cache(m, 1);
	
    for (int i = 1; i < n; i++)
    {
	    int p = 1;
        for (int j = 1; j < m; j++)
        {
	        int temp = cache[j];
            cache[j] = (int)(((long long)cache[j] + (long long)cache[j - 1] + (long long)p) % MOD);
            p = temp;
        }
    }
	
    cout << cache[m - 1];
	
    return 0;
}