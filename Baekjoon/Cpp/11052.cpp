#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int cache[1001];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cache[i] = max(cache[i], cache[i - j] + arr[j]);
        }
    }

    cout << cache[n];
}