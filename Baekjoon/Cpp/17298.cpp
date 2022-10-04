#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int num[1000001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    vector<int> v, answer;
    for (int i = n - 1; i >= 0; i--) {
        while (!v.empty() && v.back() <= num[i]) {
            v.pop_back();
        }

        if (v.empty()) answer.push_back(-1);
        else answer.push_back(v.back());

        v.push_back(num[i]);
    }

    for (int i = answer.size() - 1; i >= 0; i--) {
        cout << answer[i] << ' ';
    }
}