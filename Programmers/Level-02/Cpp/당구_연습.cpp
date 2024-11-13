#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (int i = 0; i < (int)balls.size(); i++)
    {
        int cache = INT_MAX;
        int a = balls[i][0];
        int b = balls[i][1];
        
        if (startX != a || startY <= b)
        {
            cache = min(cache, (startX - a) * (startX - a) + (startY + b) * (startY + b));
        }
        
        if (startX >= a || startY != b)
        {
            cache = min(cache, (startX - 2 * m + a) * (startX - 2 * m + a) + (startY - b) * (startY - b));
        }
        
        if (startX != a || startY >= b)
        {
            cache = min(cache, (startX - a) * (startX - a) + (startY - 2 * n + b) * (startY - 2 * n + b));
        }
        
        if (startX <= a || startY != b)
        {
            cache = min(cache, (startX + a) * (startX + a) + (startY - b) * (startY - b));
        }
        
        answer.push_back(cache);
    }
    
    return answer;
}

int main()
{
    int m, n, startX, startY;
    cin >> m >> n >> startX >> startY;

    int k;
    cin >> k;

    vector<vector<int>> balls(k, vector<int>(2));
    for (int i = 0; i < k; i++)
    {
        cin >> balls[i][0] >> balls[i][1];
    }

    vector<int> answer = solution(m, n, startX, startY, balls);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}