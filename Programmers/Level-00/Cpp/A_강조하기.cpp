#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for (int i = 0; i < (int)myString.length(); i++)
    {
        answer.push_back((myString[i] == 'a' || myString[i] == 'A') ? 'A' : tolower(myString[i]));
    }
    
    return answer;
}

int main()
{
    string myString;
    cin >> myString;

    string answer = solution(myString);
    
    cout << answer;

    return 0;
}