#include <iostream>
#include <string>

using namespace std;

int cache[26][200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'a' + i) cache[i][j]++;
            cache[i][j] += cache[i][j - 1];
        }
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char c;
        int b, e;
        cin >> c >> b >> e;
        cout << cache[c - 'a'][e] - cache[c - 'a'][b - 1] << '\n';
    }
}