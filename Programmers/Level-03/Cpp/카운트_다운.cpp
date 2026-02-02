#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> solution(int target)
{
    vector<int> answer;

    vector<pair<int, int>> cache(target + 1, { 1000000,0 });
    cache[0] = { 0,0 };

    for (int i = 0; i <= target; i++)
    {
        if (cache[i].first == 1000000)
        {
            continue;
        }

        for (int j = 1; j <= 20; j++)
        {
            if (i + j <= target)
            {
                int a = cache[i].first + 1;
                int b = cache[i].second + 1;
                int index = i + j;

                if (a < cache[index].first || (a == cache[index].first && b > cache[index].second))
                {
                    cache[index] = { a,b };
                }
            }
        }

        for (int j = 1; j <= 20; j++)
        {
            if (i + j * 2 <= target)
            {
                int a = cache[i].first + 1;
                int b = cache[i].second;
                int index = i + j * 2;

                if (a < cache[index].first || (a == cache[index].first && b > cache[index].second))
                {
                    cache[index] = { a,b };
                }
            }
        }

        for (int j = 1; j <= 20; j++)
        {
            if (i + j * 3 <= target)
            {
                int a = cache[i].first + 1;
                int b = cache[i].second;
                int index = i + j * 3;

                if (a < cache[index].first || (a == cache[index].first && b > cache[index].second))
                {
                    cache[index] = { a,b };
                }
            }
        }

        if (i + 50 <= target)
        {
            int a = cache[i].first + 1;
            int b = cache[i].second + 1;
            int index = i + 50;

            if (a < cache[index].first || (a == cache[index].first && b > cache[index].second))
            {
                cache[index] = { a,b };
            }
        }
    }

    answer = { cache[target].first,cache[target].second };

    return answer;
}

int main()
{
    int target;
    cin >> target;

    vector<int> answer = solution(target);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}