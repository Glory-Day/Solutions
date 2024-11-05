#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52, 0);
    
    for (int i = 0; i < (int)my_string.length(); i++)
    {
        if ('A' <= my_string[i] && my_string[i] <= 'Z')
        {
            answer[my_string[i] - 'A']++;
        }
        else
        {
            answer[(my_string[i] - 'a') + 26]++;
        }
    }
    
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