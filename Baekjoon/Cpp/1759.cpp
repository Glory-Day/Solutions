#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int l, c;
    cin >> l >> c;

    vector<char> arr;
    for (int i = 0; i < c; i++) {
        char input;
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    vector<int> bits(l, 1);
    for (int i = 0; i < c - l; i++) {
        bits.push_back(0);
    }

    int a = 0, b = 0;
    vector<string> answer;
    string tmp = "";
    do {
        for (int i = 0; i < c; i++) {
            if (bits[i]) {
                if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
                    a++;
                }
                else {
                    b++;
                }

                tmp.push_back(arr[i]);
            }
        }

        if (a >= 1 && b >= 2) {
            answer.push_back(tmp);
        }

        a = b = 0;
        tmp.clear();
    }
    while (prev_permutation(bits.begin(), bits.end()));

    for (auto& i: answer) {
        cout << i << '\n';
    }
}