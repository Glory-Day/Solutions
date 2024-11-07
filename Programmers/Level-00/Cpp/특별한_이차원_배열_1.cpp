#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    vector<vector<int>> maps(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        maps[i][i] = 1;
    }
    
    answer = maps;
    
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
            cout << answer[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}