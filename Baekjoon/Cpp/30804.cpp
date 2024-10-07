#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int count = 0;
    int caches[10] = { 0, };

    int b = 0;
    int e = 0;
    int answer = 0;
    while (e < n)
    {
        if (caches[v[e]] == 0)
        {
            count++;
        }

        caches[v[e]]++;

        while (count > 2)
        {
            caches[v[b]]--;

            if (caches[v[b]] == 0)
            {
                count--;
            }

            b++;
        }

        e++;

        answer = max(answer, e - b);
    }

    cout << answer;

    return 0;
}