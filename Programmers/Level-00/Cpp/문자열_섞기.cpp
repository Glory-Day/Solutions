#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    
    for (int i = 0; i < (int)str1.length(); i++)
    {
        answer.push_back(str1[i]);
        answer.push_back(str2[i]);
    }
    
    return answer;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    string answer = solution(str1, str2);

    cout << answer;

    return 0;
}