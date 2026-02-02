#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int solution(string s)
{
    int answer = 1;

    static bool cache[2501][2501];
    fill(&cache[0][0], &cache[0][0] + 2501 * 2501, false);

    int length = (int)s.length();
    for (int i = 0; i < length; i++)
    {
        cache[i][i] = true;
    }

    for (int i = 0; i < length - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            cache[i][i + 1] = true;
            answer = 2;
        }
    }

    for (int i = 3; i <= length; i++)
    {
        for (int b = 0; b <= length - i; b++)
        {
            int e = b + i - 1;
            if (s[b] == s[e] && cache[b + 1][e - 1])
            {
                cache[b][e] = true;
                answer = max(answer, i);
            }
        }
    }

    return answer;
}

int main()
{
    string s;
    cin >> s;

    int answer = solution(s);

    cout << answer << '\n';

    return 0;
}