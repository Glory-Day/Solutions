#include <iostream>
#include <vector>
#include <queue>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
        vector<int> e(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int a = v[i];
                int b = v[j];
                
                g[a][b] = 1;
                e[b]++;
            }
        }

        int m;
        cin >> m;

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            
            if (g[a][b])
            {
                g[a][b] = 0;
                g[b][a] = 1;

                e[a]++;
                e[b]--;
            }
            else
            {
                g[b][a] = 0;
                g[a][b] = 1;

                e[a]--;
                e[b]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (e[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> answer;
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            if (q.empty())
            {
                flag = 2;
                
                break;
            }

            if ((int)q.size() > 1)
            {
                flag = 1;
            }

            int nd = q.front();
            q.pop();

            answer.push_back(nd);

            for (int j = 1; j <= n; j++)
            {
                if (g[nd][j])
                {
                    g[nd][j] = 0;
                    
                    if (--e[j] == 0)
                    {
                        q.push(j);
                    }
                }
            }
        }

        switch (flag)
        {
            case 2:
                cout << "IMPOSSIBLE\n";
                break;
            case 1:
                cout << "?\n";
                break;
            case 0:
            {
                for (int i = 0; i < n; i++)
                {
                    cout << answer[i] << ' ';
                }

                cout << "\n";

                break;
            }
            default:
                break;
        }
    }

    return 0;
}