#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    int answer = 0;
    if (n % 2) {
        answer = arr[n / 2];
    }
    else {
        int a = arr[n / 2 - 1];
        int b = arr[n / 2];

        int c = 0, d = 0;
        for (int i = 0; i < n; i++) {
            c += abs(arr[i] - a);
            d += abs(arr[i] - b);
        }

        if (c <= d) {
            answer = a;
        }
        else {
            answer = b;
        }
    }

    cout << answer;
}