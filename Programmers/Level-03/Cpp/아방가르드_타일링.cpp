#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int solution(int n)
{
    int answer = 0;

    const int P = 1000000007;

    vector<pair<long long, long long>> cache(100001, { 0LL,0LL });
    
    cache[0] = { 1LL,1LL };
    cache[1] = { 1LL,1LL };
    cache[2] = { 3LL,3LL };
    cache[3] = { 10LL,11LL };
    
    for (int i = 4; i <= n; i++)
    {
        cache[i].first = cache[i - 1].first + cache[i - 3].first;
        cache[i].first += cache[i - 2].second * 2;
        cache[i].first += cache[i - 3].second * 4;
        cache[i].first += cache[i - 4].second * 2;
        cache[i].first %= P;

        cache[i].second = cache[i - 3].second + cache[i].first;
        cache[i].second %= P;
    }

    answer = cache[n].first % P;

    return answer;
}

int main()
{
    int n;
    cin >> n;

    int answer = solution(n);

    cout << answer << '\n';

    return 0;
}