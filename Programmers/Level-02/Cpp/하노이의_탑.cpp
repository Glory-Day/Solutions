#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& vv, const int n, const int a, const int b, const int c)
{
    if (0 < n)
    {
        dfs(vv, n - 1, a, c, b);
        vv.push_back({ a,c });
        dfs(vv, n - 1, b, a, c);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    dfs(answer, n, 1, 2, 3);
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> answer = solution(n);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i][0] << ' ' << answer[i][1] << '\n';
    }

    return 0;
}