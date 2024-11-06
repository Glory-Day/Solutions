#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (answer.empty())
        {
            answer.push_back(arr[i]);
        }
        else if (answer.back() == arr[i])
        {
            answer.pop_back();
        }
        else
        {
            answer.push_back(arr[i]);
        }
    }
    
    if (answer.empty())
    {
        answer.push_back(-1);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> answer = solution(arr);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}