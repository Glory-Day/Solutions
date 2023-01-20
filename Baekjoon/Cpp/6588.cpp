#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<bool> cache(1000001, true);
    for (int i = 3; i <= 1000000; i++) {
        if (cache[i]) {
            for (int j = 2; i * j <= 1000000; j++) {
                cache[i * j] = false;
            }
        }
    }

    vector<int> arr;
    while (true) {
        int input;
        cin >> input;

        if (input == 0) {
            break;
        }

        arr.push_back(input);
    }

    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool chk = true;
        for (int j = 3; j <= arr[i]; j++) {
            if (cache[j] && cache[arr[i] - j]) {
                cout << arr[i] << " = " << j << " + " << arr[i] - j << '\n';
                chk = false;
                break;
            }
        }

        if (chk) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
}