#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

#define MAX 1000000

using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    
    vector<bool> visited(MAX + 1, false);
    visited[x] = true;
    
    queue<pair<int, int>> q;
    q.push({ x,0 });
    
    vector<int> caches = { 0,0,0 };
    while (q.empty() == false)
    {
        auto p = q.front();
        q.pop();
        
        if (p.first == y)
        {
            answer = p.second;
            
            break;
        }
        
        caches[0] = p.first + n;
        caches[1] = 2 * p.first;
        caches[2] = 3 * p.first;
        for (const auto& i: caches)
        {
            if (i <= MAX && visited[i] == false)
            {
                visited[i] = true;
                
                q.push({ i,p.second + 1 });
            }
        }
    }
    
    return answer;
}

int main()
{
    int x, y, n;
    cin >> x >> y >> n;

    int answer = solution(x, y, n);

    cout << answer;

    return 0;
}