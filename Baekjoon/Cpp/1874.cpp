#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int nums[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> v;
    string answer = "";

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
        answer += '+';

        while(!v.empty() && v.back() == nums[idx]) {
            v.pop_back();
            answer += '-';
            idx++;
        }
    }

    if (v.empty()) {
        for (char& i: answer) {
            cout << i << '\n';
        }
    } 
    else cout << "NO";
}