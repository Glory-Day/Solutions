#include <iostream>
#include <vector>

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

    int cnt = 0;
    vector<int> answer(n);
    for (int i = 1; i <= 1000; i++) {
        for (int j = 0; j < n; j++) {
            if (i == arr[j]) {
                answer[j] = cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }
}