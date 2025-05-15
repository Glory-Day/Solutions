#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	
	int j = (int)b.size() - 1;
	int cnt = 0;
	for (int i = (int)a.size() - 1; i >= 0; i--)
	{
		if (a[i] == b[j])
		{
			j--;
		}
		else
		{
			cnt++;
		}
	}
	
	int caches[26][2] = { 0, };
	for (int i = 0; i < (int)a.size(); i++)
	{
		caches[a[i] - 'A'][0]++;
		caches[b[i] - 'A'][1]++;
	}
	
	bool flag = true;
	for (int i = 0; i < 26; i++)
	{
        if (caches[i][0] != caches[i][1])
        {
            flag = false;
        }
	}
	
	cout << (flag ? cnt : -1);
    
    return 0;
}