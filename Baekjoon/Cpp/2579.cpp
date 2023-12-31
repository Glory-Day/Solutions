#include <iostream>
#include <algorithm>

using namespace std;

int arr[301];
int cache[301];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cache[1] = arr[1];
    cache[2] = arr[1] + arr[2];
    for (int i = 3; i <= n; i++) {
        cache[i] = max(cache[i - 3] + arr[i - 1] + arr[i], cache[i - 2] + arr[i]);
    }

    cout << cache[n] << '\n';
}