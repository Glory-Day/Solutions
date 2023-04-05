#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, bool> mp;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        
        if (b == "enter") {
            mp[a] = true;
        }
        else {
            mp[a] = false;
        }
    }

    for (auto i = mp.rbegin(); i != mp.rend(); i++) {
        if (i->second) {
            cout << i->first << '\n';
        }
    }
}