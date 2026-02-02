#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works)
{
    long long answer = 0;

    priority_queue<int> pq;
    for (int work: works)
    {
        pq.push(work);
    }

    for (int i = 0; i < n; i++)
    {
        if (pq.empty())
        {
            break;
        }

        int nd = pq.top();
        pq.pop();

        if (nd > 0)
        {
            pq.push(nd - 1);
        }
    }

    while (pq.empty() == false)
    {
        long long nd = (long long)pq.top();
        pq.pop();

        answer += nd * nd;
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<int> works(m);
    for (int i = 0; i < m; i++)
    {
        cin >> works[i];
    }

    int answer = solution(n, works);

    cout << answer << '\n';

    return 0;
}