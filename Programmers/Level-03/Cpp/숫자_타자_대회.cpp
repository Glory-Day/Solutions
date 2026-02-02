#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <utility>
#include <functional>

using namespace std;

int solution(string numbers)
{
    int answer = numeric_limits<int>::max();

    pair<int, int> positions[10] = { { 3,1 },{ 0,0 },{ 0,1 },{ 0,2 },{ 1,0 },{ 1,1 },{ 1,2 },{ 2,0 },{ 2,1 },{ 2,2 } };

    auto get_cost = [&](int a, int b)
    {
        if (a == b)
        {
            return 1;
        }
        
        int ax = positions[a].first;
        int ay = positions[a].second;
        int bx = positions[b].first;
        int by = positions[b].second;
        
        int dx = abs(ax - bx);
        int dy = abs(ay - by);

        return min(dx, dy) * 3 + abs(dx - dy) * 2;
    };

    int length = (int)numbers.length();
    map<pair<int, int>, int> caches;
    caches[{ 4,6 }] = 0;

    for (int i = 0; i < length; i++)
    {
        int target = numbers[i] - '0';
        map<pair<int, int>, int> temp;

        for (const auto& cache: caches)
        {
            int left = cache.first.first;
            int right = cache.first.second;
            int cost = cache.second;

            int a = get_cost(left, target);
            int b = get_cost(right, target);

            pair<int, int> na = { target,right };
            pair<int, int> nb = { left,target };

            if (left == target)
            {
                temp[na] = (temp.find(na) == temp.end() ? cost + a : min(temp[na], cost + a));
            }
            else if (right == target)
            {
                temp[nb] = (temp.find(nb) == temp.end() ? cost + b : min(temp[nb], cost + b));
            }
            else
            {
                temp[na] = (temp.find(na) == temp.end() ? cost + a : min(temp[na], cost + a));
                temp[nb] = (temp.find(nb) == temp.end() ? cost + b : min(temp[nb], cost + b));
            }
        }

        caches = temp;
    }

    for (const auto& cache: caches)
    {
        answer = min(answer, cache.second);
    }

    return answer;
}

int main()
{
    string numbers;
    cin >> numbers;

    int answer = solution(numbers);

    cout << answer;

    return 0;
}