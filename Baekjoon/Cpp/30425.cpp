#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> cache(n);
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j && s[i] != s[j])
        {
            j = cache[j - 1];
        }

        if (s[i] == s[j])
        {
            cache[i] = ++j;
        }
    }

    int d = n - cache[n - 1];
    int answer = (n - 1) / d + 1;

    cout << answer;

    return 0;
}