#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer(2);
    
    int n = (int)park.size();
    int m = (int)park[0].length();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (park[i][j] == 'S')
            {
                answer[0] = i;
                answer[1] = j;
            }
        }
    }
    
    for (int i = 0; i < (int)routes.size(); i++)
    {
        bool flag = true;
        int y = answer[0];
        int x = answer[1];
        int d = (routes[i][2] - '0');
        for (int j = 0; j < d; j++)
        {
            switch (routes[i][0])
            {
                case 'N': y--; break;
                case 'S': y++; break;
                case 'W': x--; break;
                case 'E': x++; break;
            }
            
            if ((0 <= y && y < n && 0 <= x && x < m && park[y][x] != 'X') == false)
            {
                flag = false;
            }
        }
        
        if (flag)
        {
            answer[0] = y;
            answer[1] = x;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> park(n);
    for (int i = 0; i < n; i++)
    {
        cin >> park[i];
    }

    int m;
    cin >> m;

    vector<string> routes(m);
    for (int i = 0; i < m; i++)
    {
        cin >> routes[i];
    }

    vector<int> answer = solution(park, routes);

    cout << answer[0] << ' ' << answer[1];

    return 0;
}