#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        map<string, int> mp;
        for (int j = 0; j < m; j++) {
            string a, b;
            cin >> a >> b;

            if (mp.find(b) == mp.end()) {
                mp.insert({ b,2 });
            }
            else {
                mp[b]++;
            }
        }

        int answer = 1;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            answer *= (*it).second;
        }

        cout << answer - 1 << '\n';
    }
}