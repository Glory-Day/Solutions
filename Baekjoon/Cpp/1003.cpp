#include <iostream>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

pii answer[41];
int cache[41];

int fibonacci(int n) {
    if (n == 0) {
        return cache[n];
    }
    else if (n == 1) {
        return cache[n];
    }
    else if (cache[n]) {
        return cache[n];
    }

    cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
    answer[n] = { answer[n - 1].first + answer[n - 2].first,
                answer[n - 1].second + answer[n - 2].second };
    return cache[n];
}

int main() {
    int n;
    cin >> n;

    answer[0] = { 1,0 };
    answer[1] = { 0,1 };
    cache[1] = 1;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        fibonacci(input);
        cout << answer[input].first << ' ' << answer[input].second << '\n';
    }
}