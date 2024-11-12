#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i = 0; i < (int)arr1.size(); i++) 
    {
        for (int j = 0; j < (int)arr1[i].size(); j++)
        {
            arr1[i][j] += arr2[i][j];
        }
    }

    answer = arr1;
    
    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr1(n, vector<int>(m));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr1[i][j];
        }
    }

    vector<vector<int>> arr2(n, vector<int>(m));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr2[i][j];
        }
    }

    vector<vector<int>> answer = solution(arr1, arr2);

    for (int i = 0; i < (int)answer.size(); i++) 
    {
        for (int j = 0; j < (int)answer[i].size(); j++)
        {
            cout << answer[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}