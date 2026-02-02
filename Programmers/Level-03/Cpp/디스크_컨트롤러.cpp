#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job
{
    int time;
    int duration;

    bool operator()(const Job& lhs, const Job& rhs)
    {
        return lhs.duration > rhs.duration;
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0;

    int size = jobs.size();
    
    sort(jobs.begin(), jobs.end());
    
    priority_queue<Job, vector<Job>, Job> pq;
    
    int index = 0;
    int duration = 0;

    int completed = 0;
    while (completed < size)
    {
        while (index < size && jobs[index][0] <= duration)
        {
            pq.push({jobs[index][0], jobs[index][1]});
            
            index++;
        }
        
        if (pq.empty() == false)
        {
            Job node = pq.top();
            pq.pop();
            
            duration += node.duration;
            answer += duration - node.time;
            
            completed++;
        }
        else
        {
            duration = jobs[index][0];
        }
    }

    answer /= size;
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> jobs(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i][0] >> jobs[i][1];
    }

    int answer = solution(jobs);

    cout << answer << '\n';

    return 0;
}