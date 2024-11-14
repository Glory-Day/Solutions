#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    if (a > b)
    {
        swap(a, b);
    }
    
    while (true)
    {
        if (abs(a - b) == 1 && a % 2 == 1 && b % 2 == 0)
        {
            break;
        }
        
        a = (a / 2) + (a % 2);
        b = (b / 2) + (b % 2);
        
        answer++;
    }
    
    return answer;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    int answer = solution(n, a, b);

    cout << answer;

    return 0;
}