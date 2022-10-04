#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        a.push_back(input);
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        b.push_back(input);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a.back() < b.back()) {
        cout << -1;
    }
    else {
        int answer = 0;
        while (!b.empty()) {
            answer++;
            for (int i = a.size() - 1; i >= 0; i--) {
                for (int j = b.size() - 1; j >= 0; j--) {
                    if (a[i] >= b[j]) {
                        b.erase(b.begin() + j);
                        break;
                    }
                }
            }
        }

        cout << answer;
    }
}