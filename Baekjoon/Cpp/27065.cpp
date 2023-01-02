#include <iostream>
#include <vector>

using namespace std;

bool cache[5001];

void check(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) {
            sum += i;
        }
        else if (n % i == 0) {
            sum += i + n / i;
        }
    }

    sum -= n;
    if (sum <= n) {
        cache[n] = false;
    }
    else {
        cache[n] = true;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    cache[1] = false;
    for (int i = 2; i <= 5000; i++) {
        check(i);
    }

    for (auto& i: arr) {
        if (cache[i] == true) {
            int sum = 0;
            for (int j = 1; j * j <= i; j++) {
                if (j * j == i) {
                    sum += cache[j];
                }
                else if (j != 1 && i % j == 0) {
                    sum += cache[j] + cache[i / j];
                }
            }

            if (sum == 0) {
                cout << "Good Bye\n";
                continue;
            }
        }

        cout << "BOJ 2022\n";
    }
}