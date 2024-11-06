#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (arr[i] < 50 && arr[i] % 2 == 1)
        {
            arr[i] = arr[i] * 2;
        }
        else if (arr[i] >= 50 && arr[i] % 2 == 0)
        {
            arr[i] = arr[i] / 2;
        }
    }
    
    answer = arr;
    
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