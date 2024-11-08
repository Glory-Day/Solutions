#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    for (int i = 0; i < (int)my_string.length(); i++)
    {
        if (isdigit(my_string[i]))
        {
            answer.push_back(my_string[i] - '0');
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    vector<int> answer = solution(my_string);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}