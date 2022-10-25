#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int n) {
    int answer = 1;

    while(n != 1) {
        if (n % 2 == 1) {
            n--;
            answer++;
        }
        else {
            n /= 2;
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    int answer = solution(n);

    cout << answer;
}