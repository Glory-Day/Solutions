#include <iostream>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

int pop_count(unsigned int x)
{
    x = x - ((x >> 1) & 0x55555555u);
    x = (x & 0x33333333u) + ((x >> 2) & 0x33333333u);
    x = (x + (x >> 4)) & 0x0f0f0f0fu;
    x = x + (x >> 8);
    x = x + (x >> 16);

    return static_cast<int>(x & 0x3fu);
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = INT_MAX;

    int n = (int)beginning.size();
    int m = (int)beginning[0].size();

    for (int i = 0; i < (1 << n); i++)
    {
        vector<vector<int>> current = beginning;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                for (int k = 0; k < m; k++)
                {
                    current[j][k] = 1 - current[j][k];
                }
            }
        }
        
        int column = 0;
        bool possible = true;
        for (int j = 0; j < m; j++)
        {
            bool flip = (current[0][j] != target[0][j]);
            for (int k = 0; k < n; k++)
            {
                int expected = flip ? (1 - current[k][j]) : current[k][j];
                if (expected != target[k][j])
                {
                    possible = false;
                    
                    break;
                }
            }
            
            if (possible == false)
            {
                break;
            }

            if (flip)
            {
                column++;
            }
        }
        
        if (possible)
        {
            int row = pop_count(i);
            answer = min(answer, row + column);
        }
    }
    
    return answer == INT_MAX ? -1 : answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> beginning(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> beginning[i][j];
        }
    }

    vector<vector<int>> target(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> target[i][j];
        }
    }

    int answer = solution(beginning, target);

    cout << answer << '\n';

    return 0;
}