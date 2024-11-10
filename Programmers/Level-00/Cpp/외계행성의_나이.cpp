#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    
    answer = to_string(age);
    for (int i = 0; i < (int)answer.size(); i++)
    {
        answer[i] = ((answer[i] - '0') + 'a');
    }
    
    return answer;
}

int main()
{
    int age;
    cin >> age;

    string answer = solution(age);

    cout << answer;

    return 0;
}