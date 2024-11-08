#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    int a = max(sides[0], sides[1]);
    int b = min(sides[0], sides[1]);
    
    for (int i = 1; i <= a; i++)
    {
        if (i + b > a)
        {
            answer++;
        }
    }
    
    answer += b - 1;
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> sides(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sides[i];
    }

    int answer = solution(sides);

    cout << answer;

    return 0;
}