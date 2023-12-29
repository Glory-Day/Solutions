#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool chk = false;
    map<string, bool> mp;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        if (a == "ChongChong" || b == "ChongChong") {
            mp[a] = mp[b] = true;
            continue;
        }

        if (mp[a] || mp[b]) {
            mp[a] = mp[b] = true;
        }
    }

    int answer = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        answer += it->second;
    }

    cout << answer;
}