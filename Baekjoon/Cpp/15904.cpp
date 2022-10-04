#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    string k = "CPCU";
    for (auto& i: s) {
        if (i == k.back() && !k.empty()) {
            k.pop_back();
        }
    }

    if (k.empty()) cout << "I love UCPC";
    else cout << "I hate UCPC";
}