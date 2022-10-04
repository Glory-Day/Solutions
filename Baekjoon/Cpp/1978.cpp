#include <iostream>

using namespace std;

bool cache[1001];

void check() {
    for (int i = 2; i < 1001; i++) {
        for (int j = 2; i * j < 1001; j++) {
            if (!cache[i * j]) {
                cache[i * j] = true;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    cache[1] = true;
    check();

    int answer = 0;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        answer += (!cache[input]) ? 1 : 0;
    }

    cout << answer;
}