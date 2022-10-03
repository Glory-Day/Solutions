#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    string s, p;
    getline(cin, s);
    getline(cin, p);

    int len = s.size();
    s = regex_replace(s, regex(p), "");

    cout << (len - s.size()) / p.size();
}