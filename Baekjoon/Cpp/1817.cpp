#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int answer = 0;
    if (0 < n)
    {
        deque<int> dq(n);
        for (int i = 0; i < n; i++)
        {
            cin >> dq[i];
        }

        int cache = 0;
        while (dq.empty() == false)
        {
            if (cache + dq.front() <= m)
            {
                cache += dq.front();
                dq.pop_front();

                continue;
            }

            cache = 0;

            answer++;
        }

        if (0 < cache)
        {
            answer++;
        }
    }

    cout << answer;

    return 0;
}