#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

const bool check(vector<int>& matrix, const int index, const int level)
{
    for (int i = 0; i < level; i++)
    {
        if (matrix[i] == index || abs(matrix[i] - index) == abs(level - i))
        {
            return false;
        }
    }
    
    return true;
}

void dfs(vector<int>& matrix, int& answer, const int n, const int level)
{
    if (level == n)
    {
        answer++;
        
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (check(matrix, i, level))
        {
            matrix[level] = i;
            
            dfs(matrix, answer, n, level + 1);
        }
    }
}

int solution(int n) {
    int answer = 0;
    
    vector<int> matrix(n, 0);
    
    dfs(matrix, answer, n, 0);
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    int answer = solution(n);

    cout << answer;

    return 0;
}