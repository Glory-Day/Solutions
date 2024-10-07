#include <iostream>
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

    vector<int> answer = { n };
    v.pop_back();

    for (int i = n - 1; i > 0; i--)
    {
        int j = 0;
        int cache = 0;
        while (true)
        {
            if (cache == v.back())
            {
                answer.insert(answer.begin() + j, i);
                v.pop_back();

                break;
            }

            if (i < answer[j])
            {
                cache++;
            }

            j++;
        }
    }

    for (auto& i: answer)
    {
        cout << i << ' ';
    }
}