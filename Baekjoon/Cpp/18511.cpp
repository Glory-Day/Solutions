#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{    
    int n, k;
    cin >> n >> k;

    vector<int> v(k);
    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
    }

    int answer = 0;

    function<void(int)> dfs = [&](int number)
    {
        for (int i = 0; i < k; i++)
        {
            int cache = number * 10 + v[i];
            if (cache > n)
            {
                continue;
            }

            answer = max(answer, cache);

            dfs(cache);
        }
    };

    dfs(0);

    cout << answer;

    return 0;
}