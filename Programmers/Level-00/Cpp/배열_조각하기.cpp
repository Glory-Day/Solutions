#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer(arr.begin(), arr.end());
    
    for (int i = 0; i < (int)query.size(); i++)
    {
        if (i % 2 == 0)
        {
            answer.erase(answer.begin() + query[i] + 1, answer.end());
        }
        else
        {
            answer.erase(answer.begin(), answer.begin() + query[i]);
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

    int m;
    cin >> m;

    vector<int> query(m);
    for (int i = 0; i < m; i++)
    {
        cin >> query[i];
    }

    vector<int> answer = solution(arr, query);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}