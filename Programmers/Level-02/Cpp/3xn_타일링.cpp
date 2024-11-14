#include <iostream>
#include <string>
#include <vector>

#define P 1000000007

using namespace std;

using ll = long long;

int solution(int n) {
    int answer = 0;

    ll caches[5001];
    
    caches[0] = 1;
    caches[2] = 3;
    for (int i = 4; i <= n; i += 2)
    {
        caches[i] = caches[i - 2] * 3;
        for(int j = i - 4; j >= 0; j -= 2)
        {
            caches[i] += caches[j] * 2;
        }
        
        caches[i] %= P;
    }
    
    answer = caches[n];
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    int answer = solution(n);

    cout << answer;

    return 0;
}