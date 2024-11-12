#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    vector<int> arr2 = arr;
    sort(arr2.begin(), arr2.end());
    
    for (auto i: arr)
    {
        if (arr2.front() != i)
        { 
            answer.push_back(i);
        }
    }

    if (answer.empty())
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

    vector<int> answer = solution(arr);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i];
    }

    return 0;
}