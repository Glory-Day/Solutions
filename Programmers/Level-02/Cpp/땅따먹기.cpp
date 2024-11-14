#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    
    int row = (int)land.size();
    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int cache = land[i][j];
            for (int k = 0; k < 4; k++)
            {
                if (j != k)
                {
                    cache = max(cache, land[i][j] + land[i - 1][k]);
                }
            }
            
            land[i][j] = cache;
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        answer = max(answer, land[row - 1][i]);
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> land(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        cin >> land[i][0] >> land[i][1] >> land[i][2] >> land[i][3];
    }

    int answer = solution(land);

    cout << answer;

    return 0;
}