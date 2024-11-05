#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (int i = 0; i < (int)queries.size(); i++)
    {
        for (int j = queries[i][0]; j <= queries[i][1]; j++)
        {
            if (j % queries[i][2] == 0)
            {
                arr[j]++;
            }
        }
    }
    
    answer = arr;
    
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

    int m;
    cin >> m;

    vector<vector<int>> queries(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    vector<int> answer = solution(arr, queries);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}