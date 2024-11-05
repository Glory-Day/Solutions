#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string number) {
    int answer = 0;
    
    for (int i = 0; i < (int)number.length(); i++)
    {
        answer += (number[i] - '0');
        answer %= 9;
    }
    
    return answer;
}

int main()
{
    string number;
    cin >> number;

    int answer = solution(number);

    cout << answer;

    return 0;
}