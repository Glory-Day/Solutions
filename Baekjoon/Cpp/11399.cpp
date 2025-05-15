#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
	
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
	
    sort(p.begin(), p.end());
	
	int answer = p[0];
    for (int i = 0; i < n - 1; i++)
    {
        p[i + 1] += p[i];
        answer += p[i + 1];
    }
	
    cout << answer;
	
	return 0;
}