#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    vector<bool> visited(n, true);
    for (int i = 0; i < (int)section.size(); i++)
    {
        visited[section[i] - 1] = false;
    }
    
    vector<bool> caches;
    for (int i = 0; i < n; i++)
    {
        if ((int)caches.size() < m)
        {
            caches.push_back(visited[i]);
        }
        else
        {
            caches.clear();
            caches.push_back(visited[i]);
            
            answer++;
        }
        
        if (caches.front() == true)
        {
            caches.pop_back();
        }
    }
    
    if (caches.empty() == false)
    {
        answer++;
    }
    
    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;

    vector<int> section(n);
    for (int i = 0; i < k; i++)
    {
        cin >> section[i];
    }

    int answer = solution(n, m, section);

    cout << answer;

    return 0;
}