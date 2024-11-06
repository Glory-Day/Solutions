#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for (auto& i: myString)
    {
        answer.push_back(toupper(i));
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