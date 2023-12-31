#include <iostream>

using namespace std;

int arr[10];
int cache[10001];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cache[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= arr[i]) {
                cache[j] += cache[j - arr[i]];
            }
        }
    }

    cout << cache[k];
}