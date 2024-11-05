#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    for (int i = 0; i < (int)my_string.length(); i++)
    {
        answer.push_back(my_string.substr(i, (int)my_string.length()));
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    vector<string> answer = solution(my_string);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}