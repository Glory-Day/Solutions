#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(int n, vector<int> cores)
{
    int answer = n;

    int size = (int)cores.size();
    if (n <= size)
    {
        return answer;
    }

    answer = -1;

    auto get_count = [&](long long time)
    {
        long long count = (long long)cores.size();
        for (int& core: cores)
        {
            count += time / core;
        }

        return count;
    };

    long long left = 0LL;
    long long right = (long long)n * (*max_element(cores.begin(), cores.end()));
    long long target = 0LL;

    while (left <= right)
    {
        long long middle = (left + right) / 2LL;
        long long count = get_count(middle);

        if (count < n)
        {
            left = middle + 1LL;

            target = middle;
        }
        else
        {
            right = middle - 1LL;
        }
    }

    long long cache = get_count(target);
    for (int i = 0; i < size; i++)
    {
        if ((target + 1LL) % cores[i] == 0LL)
        {
            cache++;

            if (cache == n)
            {
                answer = i + 1;
            }
        }
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<int> cores(m);
    for (int i = 0; i < m; i++)
    {
        cin >> cores[i];
    }

    int answer = solution(n, cores);

    cout << answer << '\n';

    return 0;
}