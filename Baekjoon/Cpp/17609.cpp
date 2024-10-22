#include <iostream>
#include <string>

using namespace std;

const int dfs(string s, const int flag)
{
    int l = 0, r = (int)s.length() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            if (flag == 0)
            {
                int d = r - l;
                return (dfs(s.substr(l + 1, d), 1) == 0 || dfs(s.substr(l, d), 1) == 0) ? 1 : 2;
            }
            else
            {
                return 2;
            }
        }

        l++;
        r--;
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        cout << dfs(s, 0) << '\n';
    }

    return 0;
}