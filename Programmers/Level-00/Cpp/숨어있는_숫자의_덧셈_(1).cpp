#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    for (int i = 0; i < (int)my_string.length(); i++)
    {
        if (isdigit(my_string[i]))
        {
            answer += (my_string[i] - '0');
        }
    }
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    int answer = solution(my_string);

    cout << answer;

    return 0;
}