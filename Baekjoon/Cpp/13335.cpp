#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n, w, l;
    cin >> n >> w >> l;

    deque<int> dqa(n), dqb(w);
    for (int i = 0; i < n; i++)
    {
        cin >> dqa[i];
    }

    
    int cache = 0;
    int count = 0;
    int answer = 0;
    while (dqa.empty() == false || 0 < count)
    {
        answer++;

        if (0 < dqb[0])
        {
            cache -= dqb[0];
            count--;

            dqb[0] = 0;
        }

        if (0 < count)
        {
            dqb.pop_front();
            dqb.push_back(0);
        }

        if (dqa.empty())
        {
            continue;
        }

        int a = dqa.front();
        if (count < w && cache + a <= l)
        {
            dqa.pop_front();

            dqb[w - 1] = a;

            cache += a;
            count++;
        }
    }

    cout << answer;
}