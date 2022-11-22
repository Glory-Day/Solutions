#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a) {
        int mod = n % a;
        n = (n / a) * b;
        answer += n;
        n += mod;
    }

    return answer;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    int answer = solution(a, b, n);

    cout << answer;
}