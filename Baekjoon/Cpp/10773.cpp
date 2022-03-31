#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (input == 0) {
            v.pop_back();
        }
        else {
            v.push_back(input);
        }
    }

    ll answer = 0;
    for (int& i: v) {
        answer += i;
    }

    cout << answer;
}