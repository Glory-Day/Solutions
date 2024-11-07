#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    
    for (int i = 0; i < (int)delete_list.size(); i++)
    {
        auto iter = find(arr.begin(), arr.end(), delete_list[i]);
        if (iter != arr.end())
        {
            arr.erase(iter);
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

    int m;
    cin >> m;

    vector<int> delete_list(m);
    for (int i = 0; i < m; i++)
    {
        cin >> delete_list[i];
    }

    vector<int> answer = solution(arr, delete_list);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}