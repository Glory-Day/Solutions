#include <iostream>
#include <string>
#include <vector>

#define P 1234567

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    long long caches[2001];
    caches[0] = caches[1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        caches[i] = (caches[i - 1] + caches[i - 2]) % P;
    }
    
    answer = caches[n];
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    long long answer = solution(n);

    cout << answer;

    return 0;
}