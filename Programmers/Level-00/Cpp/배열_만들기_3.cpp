#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    
    for (int i = 0; i < (int)intervals.size(); i++)
    {
        for (int j = intervals[i][0]; j <= intervals[i][1]; j++)
        {
            answer.push_back(arr[j]);
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> intervals(2, vector<int>(2));
    for (int i = 0; i < 2; i++)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<int> answer = solution(arr, intervals);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}