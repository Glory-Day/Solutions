#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
	
    int sum = 0;
	int n = (int)s.size();
	int caches[10] = { 0, };
	for (int i = 0; i < n; i++)
    {
	    int a = s[i] - '0';
        sum += a;
        caches[a]++;
    }
	
	s.clear();
	for (int i = 9; i >= 0; i--)
	{
        s += string(caches[i], i + '0');
	}
	
	cout << ((sum % 3 == 0 && s.back() == '0') ? s : "-1");
	
	return 0;
}