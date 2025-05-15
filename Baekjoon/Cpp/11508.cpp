#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
	
	long long answer = 0LL;
	
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
		
		answer += v[i];
    }
	
    sort(v.begin(), v.end());
	
    for (int i = n - 3; i >= 0; i -= 3)
    {
	    answer -= v[i];
    }
	
    cout << answer;
	
	return 0;
}