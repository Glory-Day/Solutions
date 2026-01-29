#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> mp(n + 1, 0);
    mp[1] = (s[0] == '_');

    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == false)
        {
            continue;
        }
        
        if (i == n)
        {
            break;
        }

        int a = i + 1;
        if (a <= n && s[a - 1] == '_')
        {
            mp[a] = 1;
        }

        int b = i + k;
        if (b <= n && s[b - 1] == '_')
        {
            mp[b] = 1;
        }
    }

    cout << (mp[n] ? "YES" : "NO");

    return 0;
}