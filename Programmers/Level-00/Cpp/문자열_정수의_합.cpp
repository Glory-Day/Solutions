#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    
    for (int i = 0; i < (int)num_str.length(); i++)
    {
        answer += (num_str[i] - '0');
    }
    
    return answer;
}

int main()
{
    string num_str;
    cin >> num_str;

    int answer = solution(num_str);
    
    cout << answer;

    return 0;
}