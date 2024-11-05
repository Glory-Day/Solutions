#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    
    int i = 0;
    while (i < (int)arr.size())
    {
        if (stk.empty())
        {
            stk.push_back(arr[i++]);
        }
        else if (stk.back() < arr[i])
        {
            stk.push_back(arr[i++]);
        }
        else
        {
            stk.pop_back();
        }
    }
    
    return stk;
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