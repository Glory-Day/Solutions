#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

#define MAX 1e5

using namespace std;

int solution(vector<vector<int>> info, int n, int m)
{
    int answer = 0;

    int len = (int)info.size();
    vector<vector<int>> caches(len + 1, vector<int>(m, MAX));
    
    caches[0][0] = 0;
    for (int i = 1; i <= len; i++)
    {
        int a = info[i - 1][0];
        int b = info[i - 1][1];
        for(int j = 0; j < m; j++)
        {
            caches[i][j] = min(caches[i][j], caches[i - 1][j] + a);

            if (j + b < m)
            {
                caches[i][j + b] = min(caches[i][j + b], caches[i - 1][j]);
            }
        }
    }

    answer = MAX;
    for (int i = 0; i < m; i++)
    {
        answer = min(caches[len][i], answer);
    }

    answer = (answer >= n) ? -1 : answer;

    return answer;
}

int main()
{
    int l;
    cin >> l;

    vector<vector<int>> info(l, vector<int>(2));
    for (int i = 0; i < l; i++)
    {
        cin >> info[i][0] >> info[i][1];
    }

    int n, m;
    cin >> n >> m;

    int answer = solution(info, n, m);

    cout << answer;

    return 0;
}