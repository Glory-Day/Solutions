#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    deque<char> dq;
    for (int i = 0; i < s.size(); i++) {
        while (k && !dq.empty() && dq.back() < s[i]) {
            dq.pop_back();
            k--;
        }
        dq.push_back(s[i]);
    }

    for (int i = 0; i < dq.size() - k; i++) {
        cout << dq[i];
    }
}