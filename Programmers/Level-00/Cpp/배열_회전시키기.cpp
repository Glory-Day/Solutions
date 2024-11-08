#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    
    if (direction == "left")
    {
        for (int i = 1; i < (int)numbers.size(); i++)
        {
            answer.push_back(numbers[i]);
        }
        
        answer.push_back(numbers.front());
    }
    else
    {
        answer.push_back(numbers.back());
        
        for (int i = 0; i < (int)numbers.size() - 1; i++)
        {
            answer.push_back(numbers[i]);
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    string direction;
    cin >> direction;

    vector<int> answer = solution(numbers, direction);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}