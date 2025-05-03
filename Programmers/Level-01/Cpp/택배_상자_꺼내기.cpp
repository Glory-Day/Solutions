#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num)
{
    int answer = 0;

    int a, b;
    int index = 1;
    vector<vector<int>> v(100, vector<int>(100, 0));
    for (int i = 0; i <= n / w; i += 2)
    {
        for (int j = 0; j < w; j++)
        {
            if (index == num)
            {
                a = i, b = j;
            }

            v[i][j] = index <= n ? index++ : 0;
        }
        
        for (int j = w - 1; j >= 0; j--)
        {
            if (index == num)
            {
                a = i + 1, b = j;
            }

            v[i + 1][j] = index <= n ? index++ : 0;
        }
    }

    while (v[a][b] != 0)
    {
        a++;
        answer++;
    }

    return answer;
}

int main()
{
    int n, w, num;
    cin >> n >> w >> num;

    int answer = solution(n, w, num);

    cout << answer;

    return 0;
}