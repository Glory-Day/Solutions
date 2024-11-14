#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;
typedef long long LL;

int DP[60001];

LL fibonacci(LL i) {
    if(DP[i]) return DP[i];
    else if(i<2) return 1;
    return DP[i] = (fibonacci(i-1) + fibonacci(i-2))%MOD;
}

int solution(int n) {
    int answer = 0; DP[1] = 1;
    answer = fibonacci(n);
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