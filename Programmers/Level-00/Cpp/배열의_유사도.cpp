#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    for (int i = 0; i < (int)s1.size(); i++)
    {
        if (find(s2.begin(), s2.end(), s1[i]) != s2.end())
        {
            answer++;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> s1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s1[i];
    }

    int m;
    cin >> m;

    vector<string> s2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> s2[i];
    }

    int answer = solution(s1, s2);

    cout << answer;

    return 0;
}