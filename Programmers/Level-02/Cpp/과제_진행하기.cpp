#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

const int minute(const string& time)
{
    int h = (time[0] - '0') * 10 + (time[1] - '0');
    int m = (time[3] - '0') * 10 + (time[4] - '0');
    
    return h * 60 + m;
}

const int integer(const string& s)
{
    int result = 0;
    for (int i = (int)s.length() - 1, j = 1; i >= 0; i--, j *= 10)
    {
        result += (s[i] - '0') * j;
    }
    
    return result;
}

const bool compare(const vector<string>& a, const vector<string>& b)
{
    return minute(a[1]) < minute(b[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(), compare);
    
    int t = 0;
    vector<pair<string, int>> caches;
    for (const auto& i: plans)
    {
        int m = minute(i[1]);
        while (t < m)
        {
            if (0 < (int)caches.size())
            {
                caches.back().second--;
                
                if (caches.back().second == 0)
                {
                    answer.push_back(caches.back().first);
                    caches.pop_back();
                }
            }
            
            t++;
        }
        
        caches.push_back({ i[0],integer(i[2]) });
    }
    
    while (0 < (int)caches.size())
    {
        answer.push_back(caches.back().first);
        caches.pop_back();
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> plans(n, vector<string>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> plans[i][0] >> plans[i][1] >> plans[i][2];
    }

    vector<string> answer = solution(plans);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}