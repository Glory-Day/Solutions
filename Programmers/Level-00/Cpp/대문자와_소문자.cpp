#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for (int i = 0; i < (int)my_string.size(); i++)
    {
        if ('A' <= my_string[i] && my_string[i] <= 'Z')
        {
            answer.push_back(tolower(my_string[i]));
        }
        else
        {
            answer.push_back(toupper(my_string[i]));
        }
    }
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    string answer = solution(my_string);

    cout << answer;

    return 0;
}