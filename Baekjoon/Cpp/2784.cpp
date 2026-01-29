#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

inline string reverse(const string& s)
{
    return string{ s[2],s[1],s[0] };
}

int main()
{
    vector<string> v(6);
    for (int i = 0; i < 6; i++)
    {
        cin >> v[i];
    }

    vector<int> cache { 0,1,2,3,4,5 };
    vector<string> answer(3, "");

    do
    {
        string a = reverse(v[cache[2]]);
        string b = reverse(v[cache[3]]);

        if (v[cache[0]][2] != v[cache[1]][0] || v[cache[1]][2] != a[0] ||
            a[2] != b[0] || b[2] != v[cache[0]][0])
        {
            continue;
        }

        a = v[cache[4]];
        b = v[cache[5]];

        if (a[1] != b[1])
        {
            continue;
        }

        string c = { v[cache[0]][1],a[1],v[cache[2]][1] };
        string r = { v[cache[3]][1],a[1],v[cache[1]][1] };

        if (a != c || b != r)
        {
            continue;
        }

        answer = { v[cache[0]],r,v[cache[2]] };
        
        break;
    }
    while (next_permutation(cache.begin(), cache.end()));

    if (answer[0].empty())
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << answer[0] << "\n" << answer[1] << "\n" << answer[2] << "\n";
    }

    return 0;
}