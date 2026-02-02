#include <iostream>
#include <string>
#include <vector>

#define MAX_LENGTH 100000
#define P 1000000007

using namespace std;

int solution(int n, vector<int> money)
{
    int answer = 0;

    static int cache[MAX_LENGTH + 1];
    fill(&cache[0], &cache[0] + MAX_LENGTH + 1, 0);

    int size = (int)money.size();

    cache[0] = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = money[i]; j <= n; j++)
        {
            cache[j] += cache[j - money[i]];
            cache[j] %= P;
        }
    }

    answer = cache[n] % P;

    return answer;
}

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<int> money(m);
    for (int i = 0; i < m; i++)
    {
        cin >> money[i];
    }

    int answer = solution(n, money);

    cout << answer << '\n';

    return 0;
}