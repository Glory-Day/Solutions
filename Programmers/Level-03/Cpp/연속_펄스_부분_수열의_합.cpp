#include <iostream>
#include <vector>
#include <limits>
#include <utility>

using namespace std;

long long solution(vector<int> sequence)
{
    long long answer = 0;

    int size = (int)sequence.size();

    pair<long long, long long> a = { 0LL,numeric_limits<long long>::min() };
    pair<long long, long long> b = { 0LL,numeric_limits<long long>::min() };

    for (int i = 0; i < size; i++)
    {
        int na = sequence[i] * (i % 2 == 0 ? 1 : -1);
        int nb = sequence[i] * (i % 2 == 0 ? -1 : 1);

        a.first = max((long long)na, a.first + na);
        a.second = max(a.second, a.first);
        
        b.first = max((long long)nb, b.first + nb);
        b.second = max(b.second, b.first);
    }

    answer = max(a.second, b.second);

    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sequence[i];
    }

    long long answer = solution(sequence);

    cout << answer << '\n';

    return 0;
}