#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string message) {
    int answer = (int)message.length() * 2;
    
    return answer;
}

int main()
{
    string message;
    cin >> message;

    int answer = solution(message);

    cout << answer;

    return 0;
}