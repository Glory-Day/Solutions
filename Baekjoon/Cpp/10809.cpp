#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> counts(26, -1);
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        counts[s[i] - 'a'] = (counts[s[i] - 'a'] != -1) ? counts[s[i] - 'a'] : i;
    }

    for (int& i: counts) {
        cout << i << ' ';
    }
}