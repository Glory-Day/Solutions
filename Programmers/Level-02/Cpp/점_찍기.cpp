#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    long long nd = d;
    long long nk = k;
    for (long long i = 0; i <= nd; i += nk) {
        long long a = sqrtl(nd * nd - i * i);
        answer += (a / nk + 1ll);
    }

    return answer;
}

int main() {
    int k, d;
    cin >> k >> d;

    long long answer = solution(k, d);

    cout << answer;
}