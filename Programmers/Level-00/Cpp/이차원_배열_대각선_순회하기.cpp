#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int answer = 0;
    
    for (int i = 0; i < (int)board.size(); i++)
    {
        for (int j = 0; j < (int)board[0].size(); j++)
        {
            if (i + j <= k)
            {
                answer += board[i][j];
            }
        }
    }
    
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

    int k;
    cin >> k;

    int answer = solution(arr, k);

    cout << answer;

    return 0;
}