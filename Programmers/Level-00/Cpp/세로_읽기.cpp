#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    
    for (int i = 0; i < (int)my_string.length(); i++)
    {
        if (i % m == c - 1)
        {
            answer.push_back(my_string[i]);
        }
    }
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    int m, c;
    cin >> m >> c;

    string answer = solution(my_string, m, c);

    cout << answer;

    return 0;
}