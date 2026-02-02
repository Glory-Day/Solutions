#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;

    sort(times.begin(), times.end());
    
    long long left = 1;
    long long right = (long long)times.back() * n;
    
    answer = right;
    
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long count = 0;
        
        for (int time : times)
        {
            count += mid / time;

            if (count >= n)
            {
                break;
            }
        }
        
        if (count >= n)
        {
            right = mid - 1;

            answer = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;
    
    vector<int> times(m);
    for (int i = 0; i < m; i++)
    {
        cin >> times[i];
    }

    long long answer = solution(n, times);

    cout << answer << '\n';

    return 0;
}