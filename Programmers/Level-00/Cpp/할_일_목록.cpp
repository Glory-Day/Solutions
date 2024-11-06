#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> todo_list, vector<bool> finished) {
    vector<string> answer;
    
    for (int i = 0; i < (int)todo_list.size(); i++)
    {
        if (finished[i] == false)
        {
            answer.push_back(todo_list[i]);
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> todo_list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> todo_list[i];
    }

    vector<bool> finished(n);
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        finished[i] = input;
    }

    vector<string> answer = solution(todo_list, finished);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}