#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    
    int n = (int)arr.size();
    int m = (int)arr[0].size();
    if (n < m)
    {
        for (int j = 0; j < m - n; j++)
        {
            arr.push_back(vector<int>(m, 0));
        }
    }
    else if (n > m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - m; j++)
            {
                arr[i].push_back(0);
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

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> answer = solution(arr);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << answer[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}