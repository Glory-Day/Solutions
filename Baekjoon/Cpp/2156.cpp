#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];
int cache[10001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cache[1] = arr[1];
    cache[2] = arr[1] + arr[2];
    for (int i = 3; i <= n; i++) {
        int a = arr[i] + arr[i - 1] + cache[i - 3];
        int b = arr[i] + cache[i - 2];
        int c = cache[i - 1];

        cache[i] = max(a, max(b, c));
    }

    cout << cache[n];
}