#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> cache(1000001, 0);
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            cache[j] += i;
        }
    }

    for (int i = 2; i <= 1000000; i++) {
        cache[i] += cache[i - 1];
    }

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    for (int i = 0; i < n; i++) {
        cout << cache[arr[i]] << '\n';
    }
}