#include <iostream>
#include <string>

using namespace std;

int solution(int n)
{
    int answer = 0;
    
    string number = to_string(n);
    for (auto i: number)
    {
        answer += i - '0';
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    int answer = solution(n);

    cout << answer;

    return 0;
}