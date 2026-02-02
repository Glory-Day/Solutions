#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int answer = 0;

    int size = triangle.size();
    
    for (int i = size - 2; i >= 0; i--) 
    {
        for (int j = 0; j <= i; j++) 
        {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    answer = triangle[0][0];
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> triangle(n);
    for (int i = 1; i <= n; i++)
    {
        triangle[i - 1].resize(i);

        for (int j = 0; j < i; j++)
        {
            cin >> triangle[i][j];
        }
    }

    int answer = solution(triangle);

    cout << answer << '\n';

    return 0;
}