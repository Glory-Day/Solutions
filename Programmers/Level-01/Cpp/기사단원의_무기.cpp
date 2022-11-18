#include <iostream>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;

    vector<int> cache(number + 1, 2);
    cache[1] = 1;
    for (int i = 2; i <= number; i++) {
        for (int j = 2; i * j <= number; j++) {
            cache[i * j]++;
        }
    }

    for (int i = 1; i <= number; i++) {
        if (cache[i] > limit) {
            cache[i] = power;
        }

        answer += cache[i];
    }

    return answer;
}

int main() {
    int number, limit, power;
    cin >> number >> limit >> power;

    int answer = solution(number, limit, power);

    cout << answer;
}