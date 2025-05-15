#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
	
    return gcd(b, a % b);
}

int main()
{
    int t;
    cin >> t;
	
    while (t--)
    {
        int n;
        cin >> n;
		
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
		
        vector<int> bits = { 1,1 };
        for (int i = 2; i < n; i++)
        {
            bits.push_back(0);
	    }
		
        long long answer = 0;
        do
        {
            int tmp[2];
            for (int i = 0, j = 0; i < n; i++)
            {
                if (bits[i])
                {
                    tmp[j++] = arr[i];
                }
            }
			
            answer += gcd(tmp[0], tmp[1]);
        }
        while (prev_permutation(bits.begin(), bits.end()));
		
        cout << answer << '\n';
    }
	
	return 0;
}