#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int minute(const string& time)
{
    int h = (time[0] - '0') * 10 + (time[1] - '0');
    int m = (time[3] - '0') * 10 + (time[4] - '0');
    
    return h * 60 + m;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<int> caches(24 * 60, 0);
    for (int i = 0; i < (int)book_time.size(); i++)
    {
        int b = minute(book_time[i][0]);
        int e = minute(book_time[i][1]) + 10;
        if (24 * 60 < e)
        {
            e = 24 * 60;
        }
        
        for (int j = b; j < e; j++)
        {
            caches[j]++;
        }
    }
    
    for (const auto& i: caches)
    {
        answer = max(answer, i);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> book_time(n, vector<string>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> book_time[i][0] >> book_time[i][1];
    }

    int answer = solution(book_time);

    cout << answer;

    return 0;
}