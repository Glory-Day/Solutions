#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    
    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (flag[i] == true)
        {
            for (int j = 0; j < arr[i] * 2; j++)
            {
                answer.push_back(arr[i]);
            }
        }
        else
        {
            for (int j = 0; j < arr[i]; j++)
            {
                answer.pop_back();
            }
        }
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

    vector<bool> flag(n);
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        flag[i] = input;
    }

    vector<int> answer = solution(arr, flag);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}