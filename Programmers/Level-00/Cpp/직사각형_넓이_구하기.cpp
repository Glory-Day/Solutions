#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++)
    {
        a = max(a, abs(dots[i][0] - dots[i + 1][0]));
        b = max(b, abs(dots[i][1] - dots[i + 1][1]));
    }
    
    answer = a * b;
    
    return answer;
}

int main()
{
    vector<vector<int>> dots(4, vector<int>(2));
    for (int i = 0; i < 4; i++)
    {
        cin >> dots[i][0] >> dots[i][1];
    }

    int answer = solution(dots);

    cout << answer;

    return 0;
}