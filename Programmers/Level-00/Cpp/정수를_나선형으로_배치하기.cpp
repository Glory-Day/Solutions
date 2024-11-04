#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    
    int index = 1;
    for (int i = 0, j = n - 1; i <= j; i++, j--)
    {
        for (int k = i; k < j; k++)
        {
            answer[i][k] = index++;
        }

        for (int k = i; k < j; k++)
        {
            answer[k][j] = index++;
        }

        for (int k = j; k > i; k--)
        {
            answer[j][k] = index++;
        }

        for (int k = j; k > i; k--)
        {
            answer[k][i] = index++;
        }
    }

    if (n % 2 == 1)
    {
        answer[n / 2][n / 2] = index;
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> answer = solution(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << answer[i][j] << '\t';
        }

        cout << '\n';
    }
}