#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    if ((a + b) % 2 == 1)
    {
        answer = (a + b) * 2;
    }
    else if (a % 2 == 1 && b % 2 == 1)
    {
        answer = a * a + b * b;
    }
    else 
    {
        answer = abs(a - b);
    }
    
    return answer;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int answer = solution(a, b);

    cout << answer;

    return 0;
}