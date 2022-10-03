#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v1;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v1.push_back(input);
    }

    cin >> n;

    vector<int> v2;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v2.push_back(input);
    }

    sort(v1.begin(), v1.end());

    for (int& i: v2) {
        cout << binary_search(v1.begin(), v1.end(), i) << '\n';
    }
}