#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    vector<int> arr2;
    for (int i = 0; i < n - 1; i++) {
        arr2.push_back(arr[i + 1] - arr[i]);
    }

    int tmp = arr2[0];
    for (int i = 1; i < n; i++) {
        tmp = gcd(tmp, arr2[i]);
    }

    int answer = 0;
    for (int i = arr.front(); i <= arr.back(); i += tmp) {
        answer++;
    }

    answer -= n;

    cout << answer;
}