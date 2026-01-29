#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n * n; i++)
    {
        int x;
        cin >> x;

        pq.push(x);

        if ((int)pq.size() > n)
        {
            pq.pop();
        }
    }

    int answer = pq.top();

    cout << answer;

    return 0;
}