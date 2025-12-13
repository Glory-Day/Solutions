#include <iostream>
#include <string>
#include <cmath>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int t;
    cin >> t;

    while (t--)
    {
        string a, b;
        cin >> a >> b;

        int cache[2] = { 0,0 };
        
        int length = a.length();
        for (int i = 0; i < length; i++)
        {
            if (a[i] != b[i])
            {
                cache[a[i] - '0']++;
            }
        }

        cout << max(cache[0], cache[1]) << '\n';
    }

    return 0;
}