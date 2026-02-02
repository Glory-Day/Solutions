#include <iostream>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) 
{
    int answer = 0;

    const int P = 1000000007;

    vector<vector<int>> caches(n + 1, vector<int>(m + 1, 0));
    
    for (const auto& puddle : puddles) 
    {
        int x = puddle[0];
        int y = puddle[1];

        caches[y][x] = -1;
    }
    
    caches[1][1] = 1;
    
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            if (caches[i][j] == -1) 
            {
                caches[i][j] = 0;

                continue;
            }
            
            if (i == 1 && j == 1) 
            {
                continue;
            }
            
            int a = (i > 1 && caches[i - 1][j] != -1) ? caches[i - 1][j] : 0;
            int b = (j > 1 && caches[i][j - 1] != -1) ? caches[i][j - 1] : 0;
            
            caches[i][j] = (a + b) % P;
        }
    }

    answer = caches[n][m];
    
    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;

    vector<vector<int>> puddles(k, vector<int>(2));
    for (int i = 0; i < k; i++)
    {
        cin >> puddles[i][0] >> puddles[i][1];
    }

    int answer = solution(m, n, puddles);

    cout << answer << '\n';

    return 0;
}