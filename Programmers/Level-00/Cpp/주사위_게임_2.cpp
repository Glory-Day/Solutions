#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
    int answer = 0;
    
    if (a == b && b == c)
    {
        answer = (a + b + c) * (a * a + b * b + c * c) * (a * a * a + b * b * b + c * c * c);
    }
    else if (a == b || a == c || b == c)
    {
        answer = (a + b + c) * (a * a + b * b + c * c);
    }
    else
    {
        answer = (a + b + c);
    }
    
    return answer;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int answer = solution(a, b, c);

    cout << answer;

    return 0;
}