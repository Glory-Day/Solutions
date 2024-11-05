#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int to_integer(const string& s)
{
    int result = 0;
    for (int i = (int)s.length() - 1, j = 1; i >= 0; i--, j *= 10)
    {
        result += (s[i] - '0') * j;
    }
    
    return result;
}

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    
    for (int i = 0; i < (int)intStrs.size(); i++)
    {
        int cache = to_integer(intStrs[i].substr(s, l));
        if (cache > k)
        {
            answer.push_back(cache);
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> intStrs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> intStrs[i];
    }

    int k, s, l;
    cin >> k >> s >> l;

    vector<int> answer = solution(intStrs, k, s ,l);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}