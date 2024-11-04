#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    
    bool flag = false;
    for (int i = 0; i < (int)code.length(); i++)
    {
        if (code[i] == '1')
        {
            flag = !flag;
            
            continue;
        }
        
        if (i % 2 == (int)flag)
        {
            answer.push_back(code[i]);
        }
    }
    
    if (answer.empty())
    {
        answer = "EMPTY";
    }
    
    return answer;
}

int main()
{
    string code;
    cin >> code;

    string answer = solution(code);

    cout << answer;

    return 0;
}