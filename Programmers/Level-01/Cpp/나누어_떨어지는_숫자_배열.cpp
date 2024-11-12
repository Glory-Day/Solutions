#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for (auto i: arr)
    {
        if (i % divisor == 0)
        {
            answer.push_back(i);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if(answer.empty())
    {
        answer = { -1 };
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

    int divisor;
    cin >> divisor;

    vector<int> answer = solution(arr, n);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}