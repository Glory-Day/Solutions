#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    int answer = 0;
    
    if (angle == 180)
    {
        answer = 4;
    }
    else if (90 < angle && angle < 180)
    {
        answer = 3;
    }
    else if (angle == 90)
    {
        answer = 2;
    }
    else if (0 < angle && angle < 90)
    {
        answer = 1;
    }
    
    return answer;
}

int main()
{
    int angle;
    cin >> angle;

    int answer = solution(angle);

    cout << answer;

    return 0;
}