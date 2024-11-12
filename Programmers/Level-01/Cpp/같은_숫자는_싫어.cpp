#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    std::vector<int> answer;

    answer.push_back(arr.front());
    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (answer.back() != arr[i])
        {
            answer.push_back(arr[i]);
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

    vector<int> answer = solution(arr);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}