#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    vector<int> parent(n);

    function<int(int)> find = [&](int x)
    {
        return parent[x] == x ? parent[x] : parent[x] = find(parent[x]);
    };

    auto unite = [&](int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a != b)
        {
            parent[b] = a;
        }
    };

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (computers[i][j] == 1)
            {
                unite(i, j);
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (find(i) == i)
        {
            answer++;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> computers(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> computers[i][j];
        }
    }

    int answer = solution(n, computers);

    cout << answer << '\n';

    return 0;
}