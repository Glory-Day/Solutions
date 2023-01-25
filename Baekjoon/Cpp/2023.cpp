#include <iostream>
#include <cmath>
#include <vector>
#include <functional>

using namespace std;

bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> answer;
    function<void(int, int)> dfs = [&](int num, int lv) {
        if (lv == n) {
            answer.push_back(num);
        }

        for (int i = 1; i <= 9; i++) {
            if (isPrime(num * 10 + i)) {
                dfs(num * 10 + i, lv + 1);
            }
        }
    };
    
    int arr[4] = { 2,3,5,7 };
    for (int i = 0; i < 4; i++) {
        dfs(arr[i], 1);
    }

    for (auto& i: answer) {
        cout << i << '\n';
    }
}