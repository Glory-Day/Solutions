#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int e, vector<int> starts)
{
    vector<int> answer;

    vector<int> counts(e + 1, 0);
    for (int i = 1; i <= e; i++)
    {
        for (int j = i; j <= e; j += i)
        {
            counts[j]++;
        }
    }

    vector<int> caches(e + 1);
    caches[e] = e;

    for (int i = e - 1; i >= 1; i--)
    {
        caches[i] = (counts[i] >= counts[caches[i + 1]] ? i : caches[i + 1]);
    }

    for (int start: starts)
    {
        answer.push_back(caches[start]);
    }

    return answer;
}

int main()
{
    int e;
    cin >> e;

    int n;
    cin >> n;
    
    vector<int> starts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> starts[i];
    }
    
    vector<int> answer = solution(e, starts);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    
    return 0;
}