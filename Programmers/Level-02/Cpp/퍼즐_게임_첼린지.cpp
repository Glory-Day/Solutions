#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = INT_MAX;
    
    int len = (int)diffs.size();
    int b = 1;
    int e = 100000;
    while (b < e)
    {
        int mid = (b + e) / 2;
        
        long long sum = 0;
        for (int i = 0; i < len; i++)
        {
            if (diffs[i] <= mid)
            {
                sum += times[i];
            }
            else
            {
                sum += (times[i] + times[i - 1]) * (diffs[i] - mid) + times[i];
            }
        }
        
        if (limit < sum)
        {
            b = (mid - 1);
        }
        else 
        {
            e = mid + 1;
        }
    }

    answer = e;
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> diffs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> diffs[i];
    }

    vector<int> times(n);
    for (int i = 0; i < n; i++)
    {
        cin >> times[i];
    }

    long long limit;
    cin >> limit;

    int answer = solution(diffs, times, limit);

    cout << answer;
}