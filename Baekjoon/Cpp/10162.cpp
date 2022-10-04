#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[3] = { 300,60,10 };
    int answer[3] = { 0,0,0 };
    for (int i = 0; i < 3; i++) {
        answer[i] = n / arr[i];
        n %= arr[i];
    }

    if (n) cout << -1;
    else {
        for (int i = 0; i < 3; i++) {
            cout << answer[i] << ' ';
        }
    }
}