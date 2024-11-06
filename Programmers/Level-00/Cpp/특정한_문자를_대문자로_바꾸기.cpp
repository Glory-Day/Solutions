#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    string answer = "";
    
    for (int i = 0; i < (int)my_string.length(); i++)
    {
        if (my_string[i] == alp[0])
        {
            my_string[i] = toupper(alp[0]);
        }
    }
    
    answer = my_string;
    
    return answer;
}

int main()
{
    string my_string, alp;
    cin >> my_string >> alp;

    string answer = solution(my_string, alp);
    
    cout << answer;

    return 0;
}