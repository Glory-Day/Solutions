#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
    int n, m, k;
    cin >> n >> m >> k;
	
    vector<pii> map[1001];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({ b,c });
    }
	
    priority_queue<int> answer[1001];
    auto dijkstra = [&]()
    {
        priority_queue<pii> pq;
        pq.push({ 0,1 });
        answer[1].push(0);
		
        while (!pq.empty())
        {
            int cst = -pq.top().first;
            int nd = pq.top().second;
			
            pq.pop();
			
            for (auto i: map[nd])
            {
                int nnd = i.first;
                int ncst = i.second + cst;
				
                if ((int)answer[nnd].size() < k)
                {
                    answer[nnd].push(ncst);
                    pq.push({ -ncst,nnd });
                }
                else if (answer[nnd].top() > ncst)
                {
                    answer[nnd].pop();
                    answer[nnd].push(ncst);
                    pq.push({ -ncst,nnd });
                }
            }
        }
    };
	
    dijkstra();
	
    for (int i = 1; i <= n; i++)
    {
        if ((int)answer[i].size() != k)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << answer[i].top() << '\n';
        }
    }
	
	return 0;
}