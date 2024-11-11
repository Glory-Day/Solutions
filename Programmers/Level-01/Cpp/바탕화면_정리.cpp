#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4);
    
    answer[0] = answer[1] = INT_MAX;
    answer[2] = answer[3] = INT_MIN;
    
    for (int i = 0; i < (int)wallpaper.size(); i++)
    {
        for (int j = 0; j < (int)wallpaper[i].length(); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                answer[0] = min(answer[0], i);
                answer[1] = min(answer[1], j);
                answer[2] = max(answer[2], i + 1);
                answer[3] = max(answer[3], j + 1);
            }
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> wallpaper(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wallpaper[i];
    }

    vector<int> answer = solution(wallpaper);

    for (int i = 0; i < 4; i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}