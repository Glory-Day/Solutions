#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    deque<int> dq(people.begin(), people.end());
    
    while (1 < (int)dq.size())
    {
        if (dq.front() + dq.back() <= limit)
        {   
            dq.pop_front();
            dq.pop_back();
        }
        else
        {
            dq.pop_back();
        }
        
        answer++;
    }
    
    if (dq.empty() == false)
    {
        answer++;
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> people(n);
    for (int i = 0; i < n; i++)
    {
        cin >> people[i];
    }

    int limit;
    cin >> limit;

    int answer = solution(people, limit);

    cout << answer;

    return 0;
}