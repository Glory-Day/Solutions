#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n + 1, 0);
    vector<int> cache1(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        cache1[i] = cache1[i - 1] + arr[i];
    }

    vector<int> cache2(n + 1, 0);
    for (int i = n; i >= 0; i--) {
        cache2[i] = cache2[i + 1] + arr[i];
    }

    int a, b;
    int answer = 0;
    for (int i = 1, j = n, k = 2; k <= n - 1; k++) {
        a = cache1[k] - cache1[i];
        b = cache2[k] - cache2[j];
        answer = max(answer, a + b);
    }

    for (int i = 1, j = 2, k = n; j <= n - 1; j++) {
        a = cache1[k] - cache1[i] - arr[j];
        b = cache1[k] - cache1[j];
        answer = max(answer, a + b);
    }
    
    for (int i = n - 1, j = n, k = 1; i >= 1; i--) {
        a = cache2[k] - cache2[i];
        b = cache2[k] - cache2[j] - arr[i];
        answer = max(answer, a + b);
    }

    cout << answer;
}