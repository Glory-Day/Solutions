#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int caches[(int)1e6 + 1];
int visited[(int)1e6 + 1];

int main()
{
    int n;
    cin >> n;
	
    caches[2] = visited[2] = 1;
    caches[3] = visited[3] = 1;
	
    for (int i = 4; i <= n; i++)
    {
        int a = (i % 3 == 0) ? caches[i / 3] : INT_MAX;
        int b = (i % 2 == 0) ? caches[i / 2] : INT_MAX;
        int c = caches[i - 1];
		
		(a < b) && (a < c) ? (caches[i] = a, visited[i] = i / 3) : (b < c) ? (caches[i] = b, visited[i] = i / 2) : (caches[i] = c, visited[i] = i - 1);
		
	    caches[i]++;
    }
	
    cout << caches[n] << '\n';
    
    while (n != 0)
    {
        cout << n << ' ';
        
        n = visited[n];
    }
	
	return 0;
}