#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n, answer = 0;
    cin >> n;

    int arr[6], mx = 0;
    for (auto& i : arr) {
        cin >> i;
        answer += i;
        mx = max(i, mx);
    }

    if (n == 1) {
        answer -= mx;
    } 
    else {
        answer = 0;
        arr[0] = min(arr[0], arr[5]);
        arr[1] = min(arr[1], arr[4]);
        arr[2] = min(arr[2], arr[3]);

        sort(arr, arr + 3);
        int a = arr[0];
        int b = a + arr[1];
        int c = b + arr[2];

        answer += c * 4;
        answer += b * (4 * (n - 2) + 4 * (n - 1));
        answer += a * (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2));
    }

    cout << answer;
}