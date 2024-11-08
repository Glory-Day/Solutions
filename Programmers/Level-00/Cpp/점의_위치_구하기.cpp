#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    int answer = 0;
    
    if (dot[0] > 0 && dot[1] > 0)
    {
        answer = 1;
    }
    else if (dot[0] < 0 && dot[1] > 0)
    {
        answer = 2;
    }
    else if (dot[0] < 0 && dot[1] < 0)
    {
        answer = 3;
    }
    else if (dot[0] > 0 && dot[1] < 0)
    {
        answer = 4;
    }
    
    return answer;
}

int main()
{
    vector<int> dot(2);
    cin >> dot[0] >> dot[1];

    int answer = solution(dot);

    cout << answer;

    return 0;
}