#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    string tokens[] = { "dz=","z=","lj","nj","s=","d-","c=","c-" };
    for (string& i: tokens) {
        while (s.find(i) != string::npos) {
            s.replace(s.find(i), i.size(), "*");
        }
    }

    cout << s.size();
}