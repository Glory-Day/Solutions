#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            arr.push_back(input);
        }

        vector<int> bits = { 1,1,1,1,1,1 };
        for (int i = 0; i < n - 6; i++) {
            bits.push_back(0);
        }

        do {
            for (int i = 0; i < n; i++) {
                if (bits[i]) {
                    cout << arr[i] << ' ';
                }
            }

            cout << '\n';
        }
        while (prev_permutation(bits.begin(), bits.end()));

        cout << '\n';
    }
}