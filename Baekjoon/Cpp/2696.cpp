#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define AND &
#define OR |

using namespace std;

int main()
{
    FAST_IO;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        priority_queue<int, vector<int>, less<int>> lq;
        priority_queue<int, vector<int>, greater<int>> rq;

        vector<int> answer;
        answer.reserve((n + 1) / 2);

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (lq.size() == rq.size())
            {
                lq.push(x);
            }
            else
            {
                rq.push(x);
            }

            if ((lq.empty() OR rq.empty()) == false && lq.top() > rq.top())
            {
                int a = lq.top();
                int b = rq.top();
                lq.pop();
                rq.pop();

                lq.push(b);
                rq.push(a);
            }

            if (i % 2 == 0)
            {
                answer.push_back(lq.top());
            }
        }

        int size = (int)answer.size();
        cout << size << '\n';

        for (int i = 0; i < size; i++)
        {
            if (i > 0 && i % 10 == 0)
            {
                cout << '\n';
            }

            cout << answer[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}