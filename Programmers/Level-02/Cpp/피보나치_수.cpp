#include <iostream>
#include <string>
#include <vector>

using namespace std;

int memo[100001];

int fibonacci(int i) {
    if (i == 0) return memo[0];
    else if (i == 1) return memo[1];
    else if (memo[i]) return memo[i];
    
    return memo[i] = ((fibonacci(i - 1) % 1234567) + (fibonacci(i-2) % 1234567)) % 1234567;
}

int solution(int n) {
    int answer = 0;
    memo[0] = 0;
    memo[1] = 1;
    return fibonacci(n);
}

int main()
{
    int n;
    cin >> n;

    int answer = solution(n);

    cout << answer;

    return 0;
}