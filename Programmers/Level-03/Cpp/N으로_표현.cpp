#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n, number;
    cin >> n >> number;

    int answer = -1;
    
    unordered_set<int> cache[8];

    int a = 0;
    for (int i = 0; i < 8; i++) {
        a = a * 10 + n;
        cache[i].insert(a);
    }

    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            for (int a: cache[j]) {
                for (int b: cache[i - j - 1]) {
                    cache[i].insert(a + b);
                    cache[i].insert(a - b);
                    cache[i].insert(a * b);
                    if (b != 0) cache[i].insert(a / b);
                }
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        if (cache[i].find(number) != cache[i].end()) {
            answer = i + 1;
            break;
        }
    }

    cout << answer;
}